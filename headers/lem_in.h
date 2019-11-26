/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:45:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/26 20:21:34 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include "../libft/libft.h"
# include "file.h"
# define FD 1
# define MAX_NODE 10009

typedef struct s_room	t_room;
typedef struct s_indice	t_ind;


typedef struct			s_data
{
	int		ants;
	int		rooms;
	t_ind	*r_tab[(int)MAX_NODE];
	t_pos	info;
}						t_data;

typedef struct			s_link
{
	int				flow;
	t_room			*to;
	struct s_link	*tail;
	struct s_link	*next;
}						t_link;

typedef struct 			s_parent
{
	t_room			*room;
	struct s_parent	*next;
}						t_parent;

typedef struct			s_htparent
{
	int			total_node;
	t_parent	*head;
	t_parent	*tail;
}						t_htparent;

struct					s_room
{
	int				id;
	int				visit_group;
	int				capacity;
	t_string		name;
	t_link			*links;
	int				visited;
	t_room			*group_parent;
	t_room			*parent;
	t_htparent		*parents;
	struct s_room	*next;
};

struct					s_indice
{
	t_room	*head;
	t_room	*tail;
	t_room	*start;
	t_room	*end;
};

typedef	struct			s_queue
{
	t_room			*rooms;	
	struct s_queue	*next;
	struct s_queue	*prec;
}						t_queue;

typedef struct			s_htqueue
{
	struct s_queue	*head;
	struct s_queue	*tail;
}						t_htqueue;

typedef struct			s_path
{
	t_htparent			*paths;
	struct s_path		*next;
}						t_path;

typedef struct			s_htpath
{
	struct s_path		*head;
	struct s_path		*tail;
}						t_htpath;

typedef struct			s_group
{
	int					group_score;
	int					path_num;
	int					node_num;
	int					biggest_path_node;
	t_htpath			*path;
	struct s_group		*next;
}						t_group;

typedef struct			s_htgroup
{
	t_group				*head;
	t_group				*tail;
}						t_htgroup;

typedef struct			s_heap
{
	int			nopath;
	t_htqueue	*queue;
	t_htqueue	*visited;
}						t_heap;

typedef struct			s_lemin
{
	t_string	room;
	int			length;
	int			virtual_len;
	int			blocked;
	int			id_ant;
}						t_lemin;


void					debug(void);

void					quit(void);

t_bool					str_ispnum(t_string line);
t_bool					str_iscomment(t_string line);
t_bool					str_iscommand(t_data *data, t_string line);
t_bool					str_room_link(t_string line); 
t_bool					before_links(t_data data);
t_bool					valid_data(t_data data);

long long				get_hash_id(t_string s);

void					store_link(t_data *data, t_string line);
void					free_links(t_link **links);

long long				add_room(t_string line, t_data *data);
void					store_start(t_string line, t_ind *ind, t_data *data);
void					store_end(t_string line, t_ind *ind, t_data *data);

void					print_rooms(t_data *rooms, int link);
void					print_ices(t_ind *ices);
void					print_queue(t_queue *queue);
void					print_links(t_link *lnk);
void					print_parent(t_ind *ices);
void					print_short(t_ind *ices);
void					print_parents(t_htparent *parents);
void					print_plist(t_data *data);
void					print_path(t_path *path);
void					print_groups(t_group *group);
void					print__best_groups(t_group *group);
void					print_room_list(char ***head);

void					get_next_node(t_htqueue **queue, t_room *rooms,
						t_room *end, t_room *start);
void					enqueue(t_htqueue **queue, t_room *room);
void					dequeue(t_htqueue **queue);
void					link_queue(t_queue **queue, t_queue *new);
void					free_room(t_room *room);
void					free_queue(t_queue **queue);

void					update(t_link *link, t_room *room);

void					bfs(t_ind *ices, t_heap *heap);
void					init_heap(t_heap *heap);
void					update_graph(t_ind *ices);
void					rupdate_graph(t_ind *ices, t_room *room);
void					unvisit(t_htqueue **queue);
void					free_bfs(t_heap *heap);
void				    add_parents(t_htparent **parents, t_room *toadd,
						t_room *end);
t_htparent				*get_shortest(t_room *room, t_room *end,
						t_htparent *shortest, int *node_num);
void					get_groups(t_ind *ices, t_data *data,
						t_htgroup **groups);
t_htparent				*new_short(t_room *room, t_htparent *shortest);
t_group					*choose_group(t_group *group);

void					print_tab_2d_str(t_string **tab);
t_group					*sort_group(t_group **group);
char					***convert_chosen_group(t_group *head);
// t_lemin					**convert_chosen_group(t_group *head);
void					free_tab_2d_str(t_string **tab);
void					loop_on_chosen_group(t_string **group, int *ant,
						t_data *data);
// void	loop_on_chosen_group(t_string **tab, t_group *group, int max_ant);
void					tts_show_results(int ant_count, t_lemin **room_list);
void					tts_simulate_moves(int *current_ant, int ant_count, t_lemin **room_list);
void					free_groups(t_group **group);
// void					loop_on_chosen_group(t_string **group, int score, int ants, int node);


#endif
