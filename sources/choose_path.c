/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:17:20 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/04 15:27:29 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	get_next_node:
**		add links of nodeX to the queue
*/

void	get_next_node(t_htqueue **queue, t_room *room, t_room *end,
		t_room *start)
{
	t_link	*links;

	links = room->links;
	while (links)
	{
		if (links->to->visited == 0 && links->flow == 1 &&
			links->to != start)
		{
			enqueue(queue, links->to);
			links->to->parent = room;
			links->to->visited = 1;
			if (links->to == end)
				break ;
		}
		links = links->next;
	}
}

/*
**	get_parent_node:
**		add links of nodeX to the queue
*/

void	get_parent_node(t_htqueue **queue, t_room *room,
		t_room *end, t_room *start)
{
	t_link	*links;

	links = room->links;
	while (links)
	{
		if (links->to->visited == 0 && links->flow > 1 && links->to != start)
		{
			enqueue(queue, links->to);
			links->to->parent = room;
			links->to->visited = 1;
			if (links->to == end)
				break ;
		}
		links = links->next;
	}
}

void	free_heap(t_heap **heap)
{
	if (heap && *heap)
	{
		free((*heap)->queue);
		free(*heap);
	}
}

void	choose_path(t_heap *heap, t_room *start, t_room *end)
{
	t_room *room;

	room = heap->queue->head->rooms;
	if (room && room == start)
		get_next_node(&(heap->queue), room, end, start);
	else
	{
		if (room->capacity == 0 && room->parent->capacity == 0)
		{
			get_next_node(&(heap->queue), room, end, start);
			get_parent_node(&(heap->queue), room, end, start);
		}
		else if (room->capacity == 0 && room->parent->capacity == 1)
			get_parent_node(&(heap->queue), room, end, start);
		else if (room->capacity == 1)
			get_next_node(&(heap->queue), room, end, start);
	}
	enqueue(&(heap->visited), heap->queue->head->rooms);
}
