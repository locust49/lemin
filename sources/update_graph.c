 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:04:17 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/12 13:52:40 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_flow(t_link *links)
{
	t_link *tmp;

	tmp = links;
	while (tmp)
	{
		if (tmp->flow == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	update_minus_one(t_link *link, t_room *room)
{
	t_link  *links;

	links = link;
	while (link)
	{
		if (link->to == room)
		{
			if(link->flow > 0)
				link->flow -= 1;
			return ;
		}
		link = link->next;
	}
}

void	update_plus_one(t_link *link, t_room *room)
{
	t_link  *links;

	links = link;
	while (link)
	{
		if (link->to == room)
		{
			if (link->flow < 2)
				link->flow += 1;
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
		update_plus_one(room->links, room->parent);
		update_minus_one(room->parent->links, room);
		if (check_flow(room->links) == 1)
			room->capacity = 1;
		else 
			room->capacity = 0;
		room = room->parent;
	}
}