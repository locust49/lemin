/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 03:16:07 by slyazid           #+#    #+#             */
/*   Updated: 2019/08/02 06:59:25 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void	print_list(t_input* in)
{

	printf("ants: %d\n", in->ants);
	// printf("%d: %s\n", in->inout[0].id, in->inout[0].name);
	// printf("%d: %s\n", in->inout[1].id, in->inout[1].name);
	print_graph(in->graph);
}

void	print_graph(t_graph *graph)
{

	while (graph)
	{
		printf("%d: %s\n", graph->vertex.id, graph->vertex.name);
		graph = graph->next;
	}
}