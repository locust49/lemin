/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:46:17 by otel-jac          #+#    #+#             */
/*   Updated: 2019/10/12 18:04:21 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_node(t_htqueue **queue, t_room *room, t_room *end, t_room *start)
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
				break;
		}
		links = links->next;
	}
}

int     ingroup(t_room *room, t_ingroup *group)
{
    t_ingroup   *tmp;

    tmp = group;
    while (tmp)
    {
        if (tmp->room == room)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    get_groups(t_ind *ices)
{
    t_htgroup   *groups;
    t_htqueue   *queue;

    if (!(groups = (t_htgroup *)malloc(sizeof(t_htgroup))))
        exit(-1);
    groups->head = NULL;
    groups->tail = NULL;
    while ()
    {
        if (queue->tail == ices->start)
            break;
    }
}
