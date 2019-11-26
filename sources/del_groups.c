/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:52:33 by otel-jac          #+#    #+#             */
/*   Updated: 2019/11/24 20:13:40 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_parents(t_parent **parents)
{
	t_parent *p;
    t_parent *del;

	del = (*parents);
	while (del)
	{
		p = del->next;
        free(del);
        del = p;
	}
}

void	free_path(t_path **path)
{
	t_path *tmp;
    t_path *del;

	del = (*path);
	while (del)
	{
		tmp = del->next;
        free_parents(&(del->paths->head));
		free(del->paths);
		free(del);
        del = tmp;
	}
}

void	free_groups(t_group **group)
{
	t_group *tmp;
	t_group	*del;

	del = (*group);
	while (del)
	{
        tmp = del->next;
		free_path(&(del->path->head));
		free(del->path);
        free(del);
		del = tmp;
	}
}
