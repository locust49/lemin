/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:24:47 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/23 14:49:41 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

t_queue	*new_node(t_room *room, t_queue *precedent)
{
	t_queue	*new;

	new = (t_queue*)malloc(sizeof(t_queue));
	new->rooms = room;
	new->next = NULL;
	new->prec = precedent;
	return (new);
}

void	enqueue(t_queue **queue, t_room *room)
{
	if (!*queue)
	{
		(*queue) = new_node(room, NULL);
		(*queue)->head = *queue;
		(*queue)->tail = *queue;
	}
	else
	{
		(*queue)->tail->next = new_node(room, (*queue)->tail);
		(*queue)->tail = (*queue)->tail->next;
	}
}

/*
**	dequeue from tail; and return the dequeued :3 + update the queue;
*/

void	print_queue(t_queue *queue)
{
	while (queue)
	{
		printf("[%s]-->", queue->rooms->name);
		queue = queue->next;
	}
}

t_queue	*dequeue(t_queue **queue)
{
	t_queue	*last;

	if (!*queue)
		return (NULL);
	if (*queue && !(*queue)->next)
	{
		last = *queue;
		*queue = NULL;
		return (last);
	}
	last = (*queue)->tail;
	(*queue)->tail = (*queue)->tail->prec;
	(*queue)->tail->next = NULL;
	return (last);
}

/*
**	i don't think we need a loop to free if we gonna dequeue it :D
**	void	free_queue(t_queue *queue)
**	{
**		t_queue	*tmp;
**
**		while (queue)
**		{
**		}
**	}
*/