/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:19:26 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/01 15:34:34 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	init_heap(t_heap **heap)
// {
// 	if (!(*heap = (t_heap*)malloc(sizeof(t_heap))))
// 		exit(-1);
// 	if (!((*heap)->queue = (t_htqueue *)malloc(sizeof(t_htqueue))))
// 		exit(-1);
// 	(*heap)->queue->head = NULL;
// 	(*heap)->queue->tail = NULL;
// }

void	init_heap(t_heap *heap)
{
	if (!(heap->queue = (t_htqueue *)malloc(sizeof(t_htqueue))))
		exit(-1);
	heap->queue->head = NULL;
	heap->queue->tail = NULL;
}

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

void	free_heap(t_heap **heap)
{
	if (heap && *heap)
	{
		free((*heap)->queue);
		free(*heap);
	}
}

// void	bfs(t_ind *ices)
// {
// 	t_heap	*heap;

// 	init_heap(&heap);
// 	enqueue(&(heap->queue), ices->start);
// 	ices->start->visited = 1;
// 	while (heap->queue->head)
// 	{
// 		get_next_node(&(heap->queue), heap->queue->head->rooms);
// 		dequeue(&(heap->queue));
// 		if (heap->queue->tail->rooms == ices->end)
// 			break ;
// 	}
// 	// free_queue(&(heap->queue->head));
// 	free(heap->queue->head);
// 	free(heap->queue->tail);
// 	free(heap->queue);
// 	free(heap);
// 	// free_queue(&(heap->queue)->tail);
// 	// free_heap(&heap);
// 	// heap->queue->head ? free_queue(&(heap->queue->head)) : 0;

// 	// heap->queue ? free(heap->queue) : 0;
// }

void	bfs(t_ind *ices)
{
	t_heap	heap;

	init_heap(&heap);
	enqueue(&(heap.queue), ices->start);
	ices->start->visited = 1;
	while (heap.queue->head)
	{
		get_next_node(&(heap.queue), heap.queue->head->rooms);
		dequeue(&(heap.queue));
		if (heap.queue->tail->rooms == ices->end)
			break ;
	}
	if (heap.queue)
		while ((heap.queue)->head)
			dequeue(&(heap.queue));
	free(heap.queue);
	
	// dequeue(&(heap.queue));
	// printf("%p %s\n\n", heap.queue->tail, heap.queue->tail->rooms->name);
	// heap.queue = NULL;
	// free(heap.queue);
	// free_queue(&(heap.queue->head));
	// free(heap.queue->head);
	// free(heap.queue->tail);
	// free(heap.queue);
	// free(heap);
	// free_queue(&(heap->queue)->tail);
	// free_heap(&heap);
	// heap->queue->head ? free_queue(&(heap->queue->head)) : 0;

	// heap->queue ? free(heap->queue) : 0;
}
