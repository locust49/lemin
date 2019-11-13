/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:19:26 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/12 17:31:05 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_heap(t_heap *heap)
{
	heap->nopath = 0;
	if (!(heap->queue = (t_htqueue *)malloc(sizeof(t_htqueue))))
		exit(-1);
	if (!(heap->visited = (t_htqueue *)malloc(sizeof(t_htqueue))))
		exit(-1);
	heap->queue->head = NULL;
	heap->queue->tail = NULL;
	heap->visited->head = NULL;
	heap->visited->tail = NULL;
}

/*
**	get_next_node:
**		add links of nodeX to the queue
*/

void	get_next_node(t_htqueue **queue, t_room *room, t_room *end, t_room *start)
{
	t_link	*links;

	links = room->links;
	while (links)
	{
		if (links->to->visited == 0 && links->flow == 1 && links->to != start)
		{
			enqueue(queue, links->to);
			links->to->parent = room;
			links->to->visited = 1;
			if (links->to == end)
			{
				break;
			}
		}
		links = links->next;
	}
}

void	get_parent_node(t_htqueue **queue, t_room *room, t_room *start)
{
	t_parent	*links;

	links = room->parents->head;
	while (links)
	{
		if (links->room->visited == 0 && links->room != start)
		{
			enqueue(queue, links->room);
			links->room->parent = room;
			links->room->visited = 1;
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

/*
**	free /!\
*/

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
			get_parent_node(&(heap->queue), room, start);
		}
		else if (room->capacity == 0 && room->parent->capacity == 1)
			get_parent_node(&(heap->queue), room, start);
		else
			get_next_node(&(heap->queue), room, end, start);
		
	}
	enqueue(&(heap->visited), heap->queue->head->rooms);
	dequeue(&(heap->queue));
}

/*
**	Find shortest path ftm
*/


void	free_bfs(t_heap *heap)
{
	if (heap->queue)
		while ((heap->queue)->head)
		{
			enqueue(&(heap->visited), heap->queue->head->rooms);
			dequeue(&(heap->queue));
		}
	free(heap->queue);
	//need heap->visited free
}

void	bfs(t_ind *ices, t_heap *heap)
{
	init_heap(heap);
	enqueue(&(heap->queue), ices->start);
	ices->start->visited = 1;
	while (heap->queue->head)
	{
		heap->nopath = 0;
		choose_path(heap, ices->start, ices->end);
		if (heap->queue->tail->rooms == ices->end)
		{
			heap->nopath = 1;
			break ;
		}
	}
	free_bfs(heap);
	unvisit(&(heap->visited));
}
