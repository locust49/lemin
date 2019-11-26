/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:50:41 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/25 14:21:35 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_parent *new_parent(t_room *room)
{
	t_parent	*new;

	if (!(new = (t_parent*)malloc(sizeof(t_parent))))
		exit(-1);
	new->room = room;
	new->next = NULL;
	return (new);
}

t_htparent		*new_short(t_room *room, t_htparent *shortest)
{
	t_parent	*new;

	new = new_parent(room);
	if (shortest->head == NULL && shortest->tail == NULL)
	{
		shortest->head = new;
		shortest->tail = new;
		shortest->total_node = 1;
	}
	else
	{
		shortest->tail->next = new;
		shortest->tail = new;
		shortest->total_node++;
	}
	return (shortest);
}

t_htparent		*get_shortest(t_room *room, t_room *end, t_htparent *shortest, int *node_num)
{
	t_room		*tmp;
	t_link		*link;

	tmp = room;
	shortest = new_short(tmp, shortest);
	while (tmp != end)
	{
		link = tmp->links;
		while (link)
		{
			if (link->flow == 0)
			{
				shortest = new_short(link->to, shortest);
				*node_num += 1;
				tmp = link->to;
				break;
			}
			link = link->next;
		}
	}
	return (shortest);
}