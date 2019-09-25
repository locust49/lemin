/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:34:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/21 14:30:04 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file.h"

void	add_line(t_file **file, t_string newline)
{
	t_file	*eof;

	if (!(*file))
	{
		(*file) = (t_file*)malloc(sizeof(t_file));
		(*file)->line = ft_strdup(newline);
		(*file)->next = NULL;
		return ;
	}
	eof = *file;
	while (eof->next)
		eof = eof->next;
	eof->next = (t_file*)malloc(sizeof(t_file));
	eof->next->line = ft_strdup(newline);
	eof->next->next = NULL;
}

void	free_file(t_file **file)
{
	t_file *tmp;

	while (*file)
	{
		tmp = *file;
		*file = (*file)->next;
		free(tmp->line);
		free(tmp);
	}
	free(*file);
}

void	print_file(t_file *file)
{
	t_file *curr_line;

	curr_line = file;
	ft_putchar('\n');
	while (curr_line)
	{
		ft_putendl(curr_line->line);
		curr_line = curr_line->next;
	}
}
