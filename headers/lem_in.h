/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:45:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/04 15:38:07 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
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

typedef struct			s_parent
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

void			init_heap(t_heap *heap);
void			free_bfs_queue(t_heap *heap);
void			free_bfs_visited(t_heap *heap);
void			bfs(t_ind *ices, t_heap *heap);
t_bool			str_iscommand_comment(t_data *data, t_string line);
t_bool			str_iscoords(t_string line);
t_bool			str_room_link(t_string line);
t_bool			before_links(t_data data);
t_bool			valid_data(t_data data);
void			get_next_node(t_htqueue **queue, t_room *room, t_room *end,
				t_room *start);
void			get_parent_node(t_htqueue **queue, t_room *room,
				t_room *end, t_room *start);
void			free_heap(t_heap **heap);
void			choose_path(t_heap *heap, t_room *start, t_room *end);
t_group			*choose_group(t_group *group);
void			copy_to_chosen(int index, t_path *tmp,
				t_group *head, t_lemin **chosen);
t_lemin			**convert_chosen_group(t_group *head);
void			quit(t_data *data, t_file **file, t_lemin ***room_list, int error);
void			add_line(t_file **file, t_string newline);
void			free_file(t_file **file);
void			print_file(t_file *file);
void			free_data(t_data *data);
void			free_room_list(t_lemin ***list);
void			free_groups(t_group **group);
void			free_path(t_path **path);
void			free_parents(t_htparent **parents);
t_path			*new_path(t_room *room, t_ind *ices, int *node_num);
void			get_path(t_room *room, t_ind *ices, t_htpath **paths,
				int *node_num);
t_group			*new_groups(t_ind *ices);
void			get_groups(t_ind *ices, t_data *data, t_htgroup **groups);
int				convert_letter(int c);
long long		get_hash_id(t_string s);
void			initialize_data(t_data *data, t_ind *ices,
				t_file **file, t_lemin ***room_list);
t_bool			get_ants(t_data *data, t_string line);
t_bool			store_room(t_data *data, t_string line, t_ind *ices);
t_bool			get_graph(t_data *data, t_string line, t_ind *ices);
t_lemin			**dispatch_graph(t_ind *ices, t_data *data);
t_link			*new_link(t_room *room);
void			add_link(t_link **links, t_room *room);
t_room			*find_node(long long link_id, char *name, t_data *data);
t_bool			store_link(t_data *data, t_string line);
void			free_links(t_link **links);
t_parent		*new_parent(t_room *room);
void			new_short(t_room *room, t_htparent **shortest);
void			get_shortest(t_room *room, t_room *end,
				t_htparent **shortest, int *node_num);
int				tts_shift_path_ants(t_lemin *path);
int				tts_advance_ants(int *current_ant, int ant_count,
				t_lemin **room_list);
void			tts_print_instruction(int id_ant, t_string room);
void			tts_print_ants(t_lemin **room_list);
void			tts_show_results(t_file *file, t_data *data,
				t_ind *ices, t_lemin **room_list);
t_queue			*new_node(t_room *room);
void			enqueue(t_htqueue **queue, t_room *room);
void			dequeue(t_htqueue **queue);
void			unvisit(t_htqueue **queue);
t_room			*new_room(t_string line, int thisid);
long long		add_room(t_string line, t_data *data);
void			store_start(t_string line, t_ind *ind, t_data *data);
void			store_end(t_string line, t_ind *ind, t_data *data);
void			free_room(t_room *room);
void			tts_simulate_moves(int *current_ant, int ant_count,
				t_lemin **room_list);
int				check_links(t_link *links, t_room *room);
void			update_minus_one(t_link *link, t_room *room);
void			update_plus_one(t_link *link, t_room *room);
void			update_graph(t_ind *ices);
#endif
