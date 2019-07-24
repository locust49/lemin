/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:45:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/24 22:06:22 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# define FD 1

typedef	enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_room
{
	int		id;
	char	*name;
}				t_room;

typedef struct	s_map
{
	int				ants;
	t_room			inout[2];
	t_room			node;
	struct s_map	*next;
}				t_map;

void    		get_input(t_map *in);


void			print_usage(char **argv);
void			print_error(void);
void			print_false(void);

# endif