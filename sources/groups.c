/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:46:17 by otel-jac          #+#    #+#             */
/*   Updated: 2019/11/13 10:56:01 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*new_path(t_room *room, t_ind *ices, int *node_num)
{
	t_htparent	*shortest;
	t_path		*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	if (!(shortest = (t_htparent*)malloc(sizeof(t_htparent))))
		exit(-1);
	shortest->head = NULL;
	shortest->tail = NULL;
	shortest = new_short(ices->start, shortest);
	get_shortest(room, ices->end, &shortest, node_num);
	new->paths = shortest;
	new->next = NULL;
	return (new);
}

void			get_path(t_room *room, t_ind *ices, t_htpath **paths,
				int *node_num)
{
	t_path		*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	new = new_path(room, ices, node_num);
	if ((*paths)->head == NULL)
	{
		(*paths)->head = new;
		(*paths)->tail = new;
		return ;
	}
	(*paths)->tail->next = new;
	(*paths)->tail = new;
}

t_group			*new_groups(t_ind *ices)
{
	t_link		*link;
	t_htpath	*path;
	t_group		*new;

	link = ices->start->links;
	if (!(new = (t_group*)malloc(sizeof(t_group))))
		exit(-1);
	if (!(path = (t_htpath*)malloc(sizeof(t_htpath))))
		exit(-1);
	path->head = NULL;
	path->tail = NULL;
	new->path_num = 0;
	new->node_num = 0;
	while (link)
	{
		if (link->flow == 0)
		{
			new->path_num += 1;
			get_path(link->to, ices, &path, &new->node_num);
		}
		link = link->next;
	}
	new->path = path;
	new->next = NULL;
	return (new);
}

void			get_groups(t_ind *ices, t_data *data, t_htgroup **groups)
{
	t_group		*new;

	new = new_groups(ices);
	new->group_score = (data->ants + new->node_num) / new->path_num;
	if ((*groups)->head == NULL)
	{
		(*groups)->head = new;
		(*groups)->tail = new;
		return ;
	}
	(*groups)->tail->next = new;
	(*groups)->tail = new;
}

/*
*** function to find the best group of path for the map
*/

t_group		*choose_group(t_group *group)
{
	t_group *min;
	t_group *tmp;

	min = group;
	tmp = group;
	while (tmp)
	{
		if (tmp->group_score < min->group_score)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}