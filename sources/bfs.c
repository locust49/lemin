/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:19:26 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/24 16:14:23 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** if (!(curr = curr->next))
*/

t_queue	*get_next_node(t_data *data, t_ind *ices)
{
	t_room	*curr;
	t_queue	*next_nodes;

	next_nodes = NULL;
	curr = data->r_tab[ices->start->id]->head;
	while (curr != data->r_tab[ices->end->id]->head)
	{
		if (curr->visited == 1)
				break ;
		curr->visited = 1;
		enqueue(&next_nodes, curr);
		curr =  curr->links->next->to;
	}
	print_queue(next_nodes);
	return (next_nodes);
}

//set_summet_visited_to_zero;

void	bfs(t_data *data, t_ind *ices)
{
	t_queue *my_q;

	my_q = NULL;
	enqueue(&my_q, get_next_node(data, ices)->rooms);
	//printf();
	print_queue(my_q);
}