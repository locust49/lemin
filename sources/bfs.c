/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:19:26 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/04 21:37:12 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_heap(t_heap *heap)
{
	heap->nopath = false;
	if (!(heap->queue = (t_htqueue *)malloc(sizeof(t_htqueue))) ||
		!(heap->visited = (t_htqueue *)malloc(sizeof(t_htqueue))))
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

void	get_next_node(t_htqueue **queue, t_room *room)
{
	t_link	*links;

	links = room->links;
	while (links)
	{
		if (links->to->visited == 0 && links->flow)
		{
			enqueue(queue, links->to);
			links->to->parent = room;
			links->to->visited = 1;
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
		if (links->room != start)
		{
			enqueue(queue, links->room);
			links->room->visited = 1;
			links->room->parent = room;
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

void	choose_path(t_heap *heap, t_room *start)
{
	t_room *room;

	room = heap->queue->head->rooms;
	if (room && room == start)
		get_next_node(&(heap->queue), room);
	else
	{
		// printf("\troom->cap = %s: %d\n\troom->par->cap = %s: %d\n", room->name, room->capacity, room->parent->name, room->parent->capacity);
		if (room->capacity == 0 && room->parent->capacity == 1)
		{
			get_parent_node(&(heap->queue), room, start);
		}
		else if (room->capacity == 0 && room->parent->capacity == 0)
		{
			//printf("HEEEEEERRRRREEEE*************\n");
			get_next_node(&(heap->queue), room);
			get_parent_node(&(heap->queue), room, start);
		}
		else/* (room->capacity == 1 && room->parent->capacity == 1)*/
		{
			get_next_node(&(heap->queue), room);
			//printf("***********first\n");
		}
		
	}
	//printf("***\n");
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
	int		i=0;

	init_heap(heap);
	enqueue(&(heap->queue), ices->start);
	ices->start->visited = 1;
	while (heap->queue->head)
	{
		// heap->nopath = true;
		choose_path(heap, ices->start);
		//printf("iter %d\n[%s] : ", i, heap->queue->head->rooms->name);
		// print_queue(heap->queue->head);
		if (heap->queue->tail->rooms == ices->end)
		{
			// heap->nopath = false;
			break ;
		}
		i++;
	}
	free_bfs(heap);
	unvisit(&(heap->visited));

	//debug free
	// heap->visited->head ? free(heap->visited->head) : 0;
	// printf("heap->visited = %p\nheap->visited->head = %p", heap->visited, heap->visited->head);
	//print_queue(heap.queue->head);
}
