/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:46:17 by otel-jac          #+#    #+#             */
/*   Updated: 2019/11/25 14:26:17 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*new_path(t_room *room, t_ind *ices, int *node_num)
{
	t_path		*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	if (!(new->paths  = (t_htparent*)malloc(sizeof(t_htparent))))
		exit(-1);
	new->paths->total_node = 0;
	new->paths->head = NULL;
	new->paths->tail = NULL;
	new->paths = new_short(ices->start, new->paths);
	new->paths = get_shortest(room, ices->end, new->paths, node_num);
	new->next = NULL;
	return (new);
}

void			get_path(t_room *room, t_ind *ices, t_htpath **paths,
				int *node_num)
{
	t_path		*new;

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

void			init_groups(t_htpath **path, t_group **new)
{

		if (!((*new) = (t_group*)malloc(sizeof(t_group))))
			exit(-1);
		if (!((*path) = (t_htpath*)malloc(sizeof(t_htpath))))
			exit(-1);
		(*path)->head = NULL;
		(*path)->tail = NULL;
		(*new)->path_num = 0;
		(*new)->node_num = 0;
}

t_group			*new_groups(t_ind *ices)
{
	t_link		*link;
	t_htpath	*path;
	t_group		*new;

	link = ices->start->links;
	init_groups(&path, &new);
	while (link)
	{
		if (link->flow == 0)
		{
			new->path_num += 1;
			get_path(link->to, ices, &path, &new->node_num);
		}
		link = link->next;
	}
	new->biggest_path_node = 0;
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

void		swap_paths(t_path **path0, t_path **path1)
{
	t_htparent	*swap;

	swap = (*path0)->paths;
	(*path0)->paths = (*path1)->paths;
	(*path1)->paths = swap;
}

t_group		*sort_group(t_group **tosort)
{
	t_group		*head;
	t_path		*tmp0;
	t_path		*tmp1;
	t_path		*last;

	head = *tosort;
	tmp0 = head->path->head;
	while (tmp0)
	{
		tmp1 = tmp0->next;
		while (tmp1)
		{
			if (tmp0->paths->total_node > tmp1->paths->total_node)
				swap_paths(&tmp0, &tmp1);
			tmp1 = tmp1->next;
		}
		if (!tmp0->next)
			last = tmp0;
		tmp0 = tmp0->next;
	}
	*tosort = head;
	head->biggest_path_node = last->paths->total_node;
	return (head);
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
	return (sort_group(&min));
}