/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:45:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/22 21:30:01 by slyazid          ###   ########.fr       */
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
	t_room			*to;
	struct s_link	*tail;
	struct s_link	*next;
}						t_link;

struct					s_room
{
	int				id;
	t_string		name;
	t_link			*links;
	int				visited;
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
	struct s_queue	*head;
	struct s_queue	*tail;
}						t_queue;

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

t_queue					*get_next_node(t_data *data, t_ind *ices);
void					enqueue(t_queue **queue, t_room *room);

#endif
