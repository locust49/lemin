/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:04:17 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/25 12:14:18 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	update_minus_one(t_link *link, t_room *room)
{
	t_link  *links;

	links = link;
	while (link)
	{
		if (link->to == room)
		{
			link->flow = 1 - link->flow;
			return ;
		}
		link = link->next;
	}
}

void	update_graph(t_ind *ices)
{
	t_room  *room;

	room = ices->end;
	while (room != ices->start)
	{
		if (room->capacity == 0 && room->parent->capacity == 0)
			update_minus_one(room->links, room->parent);
		else
		{
			update_minus_one(room->parent->links, room);
			add_parents(&(room->parents), room->parent, ices->end);
		}
		if (room != ices->end)
			room->capacity = 0;
		room = room->parent;
	}
}

void	update_link(t_link *link, t_room *room)
{
	if (!link)
		return ;
	if (link->to == room)
		link->flow = 1 - link->flow;
	else
		update_link(link->next, room);
}

void	rupdate_graph(t_ind *ices, t_room *room)
{
	if (room == ices->start) 
		return ;
	update_link(room->parent->links, room);
	rupdate_graph(ices, room->parent);
}