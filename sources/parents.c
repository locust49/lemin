/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:50:41 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/25 13:29:30 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_parent *new_parent(t_room *room)
{
	t_parent	*new;

	if (!(new = (t_parent*)malloc(sizeof(t_parent))))
		exit(-1);
	new->room = room;
	new->next = NULL;
	return (new);
}

void	new_short(t_room *room, t_htparent **shortest)
{
	if ((*shortest)->head == NULL)
	{
		(*shortest)->head = new_parent(room);
		(*shortest)->tail = (*shortest)->head;
		(*shortest)->total_node = 1;
	}
	else
	{
		(*shortest)->tail->next = new_parent(room);
		(*shortest)->tail = (*shortest)->tail->next;
		(*shortest)->total_node += 1;
	}
}

void		get_shortest(t_room *room, t_room *end, t_htparent **shortest, int *node_num)
{
	t_room		*tmp;
	t_link		*link;

	tmp = room;
	new_short(tmp, shortest);
	while (tmp != end)
	{
		link = tmp->links;
		while (link)
		{
			if (link->flow == 0)
			{
				*node_num += 1;
				new_short(link->to, shortest);
				tmp = link->to;
				break ;
			}
			link = link->next;
		}
		link = link->next;
	}
}
