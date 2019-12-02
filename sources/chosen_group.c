/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chosen_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 07:14:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/02 07:36:52 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	sort the chosen group to get the shortest paths first
*/

static void		swap_paths(t_path **path0, t_path **path1)
{
	t_htparent	*swap;

	swap = (*path0)->paths;
	(*path0)->paths = (*path1)->paths;
	(*path1)->paths = swap;
}

static t_group	*sort_group(t_group **tosort)
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

t_group			*choose_group(t_group *group)
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

void			copy_to_chosen(int index, t_path *tmp,
				t_group *head, t_lemin **chosen)
{
	t_parent	*p_tmp;
	int			i_room;

	i_room = 0;
	p_tmp = tmp->paths->head;
	while (i_room < head->biggest_path_node)
	{
		(chosen[index][i_room]).room = tmp->paths->head ?
		tmp->paths->head->room->name : NULL;
		chosen[index][i_room].id_ant = -1;
		tmp->paths->head ? tmp->paths->head = tmp->paths->head->next : 0;
		i_room += 1;
	}
	chosen[index][i_room].room = NULL;
	tmp->paths->head = p_tmp;
}

t_lemin			**convert_chosen_group(t_group *head)
{
	t_lemin		**chosen;
	t_path		*tmp;
	int			index;
	t_parent	*p_tmp;
	t_path		*path_tmp;

	index = -1;
	chosen = (t_lemin**)malloc(sizeof(t_lemin*) * (head->path_num + 1));
	tmp = head->path->head;
	path_tmp = tmp;
	while (++index < head->path_num)
	{
		chosen[index] = (t_lemin *)malloc(sizeof(t_lemin) *
					(1 + head->biggest_path_node));
		chosen[index]->length = tmp->paths->total_node;
		chosen[index]->virtual_len = 0;
		chosen[index]->blocked = 0;
		p_tmp = tmp->paths->head;
		copy_to_chosen(index, tmp, head, chosen);
		tmp = tmp->next;
	}
	tmp = path_tmp;
	chosen[index] = NULL;
	return (chosen);
}
