/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:24:47 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/02 06:35:29 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*new_node(t_room *room)
{
	t_queue	*new;

	new = (t_queue*)malloc(sizeof(t_queue));
	new->rooms = room;
	new->next = NULL;
	new->prec = NULL;
	return (new);
}

/*
**	add to queue and set the new head;
*/

void	enqueue(t_htqueue **queue, t_room *room)
{
	t_queue *new;

	new = new_node(room);
	if (!(*queue)->head)
	{
		(*queue)->head = new;
		(*queue)->tail = new;
		return ;
	}
	new->prec = (*queue)->tail;
	(*queue)->tail->next = new;
	(*queue)->tail = new;
}

/*
**	dequeue from tail; and free the dequeued :3 + update the queue;
*/

void	dequeue(t_htqueue **queue)
{
	t_queue	*head;

	head = NULL;
	if (!(*queue)->head)
		return ;
	head = (*queue)->head;
	(*queue)->head = ((*queue)->head->next) ? (*queue)->head->next : NULL;
	head ? free(head) : 0;
}

void	unvisit(t_htqueue **queue)
{
	t_queue *tmp;

	tmp = (*queue)->head;
	while (tmp)
	{
		tmp->rooms->visited = 0;
		tmp->rooms->visit_group = 0;
		dequeue(queue);
		tmp = (*queue)->head;
	}
	free(tmp);
}
