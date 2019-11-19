/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:50:41 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/18 17:08:36 by slyazid          ###   ########.fr       */
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

void    add_parents(t_htparent **parents, t_room *toadd, t_room *end)
{
	if (toadd != end)
	{
		if (!(*parents))
		{
			if (!(*parents = (t_htparent*)malloc(sizeof(t_htparent))))
				exit(-1);
			(*parents)->total_node = 0;
			(*parents)->head = new_parent(toadd);
			(*parents)->tail = (*parents)->head;
			return ;
		}
		(*parents)->tail->next = new_parent(toadd);
		(*parents)->tail = (*parents)->tail->next;
	}
}

t_htparent		*new_short(t_room *room, t_htparent *shortest)
{
	t_parent	*new;

	if (!(new = malloc(sizeof(t_parent))))
		exit(-1);
	new->room = room;
	(shortest->total_node) += 1;
	new->next = NULL;
	if (shortest->head == NULL)
	{
		shortest->head = new;
		shortest->tail = new;
	}
	else
	{
		shortest->tail->next = new;
		shortest->tail = new;
	}
	return (shortest);
}

void		get_shortest(t_room *room, t_room *end, t_htparent **shortest, int *node_num)
{
	t_room		*tmp;
	t_link		*link;

	tmp = room;
	(*shortest) = new_short(tmp, (*shortest));
	while (tmp != end)
	{
		link = tmp->links;
		while (link)
		{
			if (link->flow == 0)
			{
				*node_num += 1;
				(*shortest) = new_short(link->to, (*shortest));
				tmp = link->to;
				break;
			}
			link = link->next;
		}
	}
}