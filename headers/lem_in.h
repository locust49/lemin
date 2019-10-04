/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:45:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/04 20:59:28 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <fcntl.h>
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
	t_parent	*head;
	t_parent	*tail;
}						t_htparent;

struct					s_room
{
	int				id;
	int				capacity;
	t_string		name;
	t_link			*links;
	int				visited;
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


typedef struct			s_heap
{
	int			nopath;
	t_htqueue	*queue;
	t_htqueue	*visited;
}						t_heap;

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

void					get_next_node(t_htqueue **queue, t_room *rooms);
void					enqueue(t_htqueue **queue, t_room *room);
void					dequeue(t_htqueue **queue);
void					link_queue(t_queue **queue, t_queue *new);
void					free_room(t_room *room);
void					free_queue(t_queue **queue);

void					update(t_link *link, t_room *room);

void					bfs(t_ind *ices, t_heap *heap);
void					init_heap(t_heap *heap);
void    				update_graph(t_ind *ices);
void    				rupdate_graph(t_ind *ices, t_room *room);
void					unvisit(t_htqueue **queue);
void					free_bfs(t_heap *heap);

void				    add_parents(t_htparent **parents, t_room *toadd);
#endif
