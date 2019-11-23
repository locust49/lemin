/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/23 14:52:42 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lemin	**convert_chosen_group(t_group *head)
{
	t_lemin		**chosen;
	t_path		*tmp;
	int			index;
	int			i_room;

	index = 0;
	chosen = (t_lemin**)malloc(sizeof(t_lemin*) * (head->path_num + 1));
	tmp = head->path->head;
	while (index < head->path_num)
	{
		chosen[index] = (t_lemin *)malloc(sizeof(t_lemin) *
						(1 + head->biggest_path_node));
		i_room = 0;
		chosen[index]->length = tmp->paths->total_node;
		chosen[index]->virtual_len = 0;
		chosen[index]->blocked = 0;
		while (i_room < head->biggest_path_node)
		{
			(chosen[index][i_room]).room = tmp->paths->head ?
			ft_strdup(tmp->paths->head->room->name) : NULL;
			chosen[index][i_room].id_ant = -1;
			tmp->paths->head ? tmp->paths->head = tmp->paths->head->next : 0;
			i_room += 1;
		}
		chosen[index][i_room].room = NULL;
		tmp = tmp->next;
		index += 1;
	}
	chosen[index] = NULL;
	return (chosen);
}

int		tts_shift_path_ants(t_lemin *path)
{
	size_t	index;
	int		last_ant;
	int		this_ant;
	int		is_empty;

	index = 1;
	last_ant = -1;
	is_empty = 1;
	while (path[index].room)
	{
		if (path[index].id_ant != -1)
			is_empty = 0;
		this_ant = path[index].id_ant;
		path[index].id_ant = last_ant;
		last_ant = this_ant;
		index++;
	}
	return (is_empty);
}

int		tts_advance_ants(int *current_ant, int ant_count, t_lemin **room_list)
{
	size_t	index;
	int		ended;

	index = 0;
	ended = 1;
	while (room_list[index])
	{
		ended &= tts_shift_path_ants(room_list[index]);
		index++;
	}
	tts_simulate_moves(current_ant, ant_count, room_list);
	return (ended);
}

void	tts_simulate_moves(int *current_ant, int ant_count, t_lemin **room_list)
{
	size_t	index;
	t_lemin	*best_route;
	int		best_length;
	int		ant_to_decide;

	ant_to_decide = *current_ant;
	for (int i = 0; room_list[i]; i++)
	{
		room_list[i]->blocked = 0;
		room_list[i]->virtual_len = room_list[i]->length;
	}
	while (ant_to_decide <= ant_count)
	{
		best_length = __INT_MAX__;
		best_route = NULL;
		index = 0;
		while (room_list[index])
		{
			if (room_list[index]->virtual_len < best_length ||
				(room_list[index]->virtual_len == best_length &&
				room_list[index]->blocked == 0))
			{
				best_route = room_list[index];
				best_length = room_list[index]->virtual_len;
			}
			index++;
		}
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

void	tts_print_ants(t_lemin **room_list)
{
	size_t	index;
	size_t	jndex;
	t_bool	draw_nothing;

	index = 0;
	draw_nothing = true;
	while (room_list[index])
	{
		jndex = 1;
		while (room_list[index][jndex].room && room_list[index][jndex].id_ant != 0)
		{
			if (room_list[index][jndex].id_ant == -1)
			{
				jndex++;
				continue ;
			}
			draw_nothing = false;
			write(1, "L", 1);
			ft_putnbr(room_list[index][jndex].id_ant);
			write(1, "-", 1);
			ft_putstr(room_list[index][jndex].room);
			write(1, " ", 1);
			jndex++;
		}
		index++;
	}
	draw_nothing == false ? write(1, "\n", 1) : 0;
}

void	tts_show_results(int ant_count, t_lemin **room_list)
{
	int	current_ant;
	int	ended;

	current_ant = 1;
	ended = 0;
	while (current_ant <= ant_count || !ended || (!ended && ant_count == 1))
	{
		if (!ended && current_ant == 1)
			current_ant -= 1;
		ended = tts_advance_ants(&current_ant, ant_count, room_list);
		tts_print_ants(room_list);
	}
}