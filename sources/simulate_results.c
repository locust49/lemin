/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_results.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 07:12:56 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/02 07:32:27 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	tts_initialize_simulation(t_lemin **room_list)
{
	int i;

	i = 0;
	while (room_list[i])
	{
		room_list[i]->blocked = 0;
		room_list[i]->virtual_len = room_list[i]->length;
		i += 1;
	}
}

static void	tts_set_best_route(t_lemin **room_list, t_lemin **best_route)
{
	size_t	index;
	int		best_length;

	best_length = __INT_MAX__;
	index = 0;
	while (room_list[index])
	{
		if (room_list[index]->virtual_len < best_length ||
			(room_list[index]->virtual_len == best_length &&
			room_list[index]->blocked == 0))
		{
			*best_route = room_list[index];
			best_length = room_list[index]->virtual_len;
		}
		index++;
	}
}

void		tts_simulate_moves(int *current_ant, int ant_count,
			t_lemin **room_list)
{
	t_lemin	*best_route;
	int		ant_to_decide;

	ant_to_decide = *current_ant;
	tts_initialize_simulation(room_list);
	while (ant_to_decide <= ant_count)
	{
		best_route = NULL;
		tts_set_best_route(room_list, &best_route);
		if (best_route)
		{
			if (!best_route->blocked)
			{
				best_route[1].id_ant = *current_ant;
				best_route->blocked = 1;
				(*current_ant)++;
			}
			best_route->virtual_len++;
		}
		ant_to_decide++;
	}
}
