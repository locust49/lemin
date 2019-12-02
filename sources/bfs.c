/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:19:26 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/27 19:18:04 by slyazid          ###   ########.fr       */
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
**	Find shortest path ftm
** need heap->visited free
*/

void	free_bfs_queue(t_heap *heap)
{
	if (heap->queue)
		while ((heap->queue)->head)
		{
			enqueue(&(heap->visited), heap->queue->head->rooms);
			dequeue(&(heap->queue));
		}
	free(heap->queue);
}

void	free_bfs_visited(t_heap *heap)
{
	if (heap->visited)
		while ((heap->visited)->head)
			dequeue(&(heap->visited));
	free(heap->visited);
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
	free_bfs_queue(heap);
	unvisit(&(heap->visited));
	free_bfs_visited(heap);
}
