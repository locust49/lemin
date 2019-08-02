/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:45:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/08/02 07:00:15 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# define FD 1

typedef char *	string;

typedef	enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_room
{
	int		id;
	string	name;
}				t_room;

typedef struct	s_graph
{
	t_room			vertex;
	struct s_graph	*next;
}				t_graph;

typedef struct	s_input
{
	int			ants;
	t_graph		*graph;
	// t_graph		*start;
	// t_graph		*end;
}				t_input;

typedef struct	s_flags
{
	unsigned char	i:1;
	unsigned char	x:1;
	unsigned char	o:1;
	unsigned char	l:1;
	unsigned char	r:1;
}				t_flag;



void    		get_input(t_input *in);

/*
**				error_handling:
*/

void			print_usage(string filename);
void			print_error(void);
void			print_false(int Letter);

/*
**				print_tools:
*/

void			print_list(t_input* in);
void			print_graph(t_graph *graph);

# endif