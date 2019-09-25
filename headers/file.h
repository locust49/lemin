/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:15:12 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/21 14:32:45 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "../libft/libft.h"

typedef struct	s_file
{
	t_string		line;
	struct s_file	*next;
}				t_file;

typedef struct	s_position
{
	int		room;
	int		link;
	int		start;
	int		end;
}				t_pos;

void			add_line(t_file **file, t_string newline);
void			free_file(t_file **file);
void			print_file(t_file *file);

#endif
