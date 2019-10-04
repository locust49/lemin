/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:04:17 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/03 22:59:13 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	update_default(t_ind *ices)
// {
// 	t_room  *room;
// 	t_link  *link;

// 	room = ices->end;
// 	while (room != ices->start)
// 	{
// 		link = room->parent->links;
// 		while (link)
// 		{
// 			if (link->to == room)
// 			{
// 				link->flow = 1 - link->flow;
// 				break ;
// 			}
// 			link = link->next;
// 		}
// 		room->capacity = 1 - room->capacity;
// 		if (room != ices->start)
// 			add_parents(&(room->parents), room->parent);	
// 		room = room->parent;
// 	}
// }

void	update(t_link *link, t_room *room)
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
	// t_link  *link;

	room = ices->end;
	while (room != ices->start)
	{
		printf("%s\n", room->name);
		//sleep(1);
		if (room->capacity == 0 && room->parent->capacity == 0)
			update(room->links, room->parent);
		else
		{
			update(room->parent->links, room);
			add_parents(&(room->parents), room->parent);
			room->capacity = 0;
		}
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