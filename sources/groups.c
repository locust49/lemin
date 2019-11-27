/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:46:17 by otel-jac          #+#    #+#             */
/*   Updated: 2019/11/27 15:46:41 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			*new_path(t_room *room, t_ind *ices, int *node_num)
{
	t_htparent	*shortest;
	t_path		*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	if (!(shortest = (t_htparent*)malloc(sizeof(t_htparent))))
		exit(-1);
	shortest->total_node = 0;
	shortest->head = NULL;
	shortest->tail = NULL;
	new_short(ices->start, &shortest);
	room != ices->end ? get_shortest(room, ices->end, &shortest, node_num) : 0;
	new->paths = shortest;
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

t_group			*new_groups(t_ind *ices)
{
	t_link		*link;
	t_group		*new;

	link = ices->start->links;
	if (!(new = (t_group*)malloc(sizeof(t_group))))
		exit(-1);
	if (!(new->path = (t_htpath*)malloc(sizeof(t_htpath))))
		exit(-1);
	new->path->head = NULL;
	new->path->tail = NULL;
	new->path_num = 0;
	new->node_num = 0;
	while (link)
	{
		if (link->flow == 0)
		{
			new->path_num += 1;
			get_path(link->to, ices, &new->path, &new->node_num);
		}
		link = link->next;
	}
	new->biggest_path_node = 0;
	new->next = NULL;
	return (new);
}

/*
**	Store the groups with the paths that don't intersect.
*/

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
**	sort the chosen group to get the shortest paths first
*/

void	swap_paths(t_path **path0, t_path **path1)
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
		!tmp0->next ? last = tmp0 : 0;
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
