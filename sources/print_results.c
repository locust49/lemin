/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/02 07:32:56 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			tts_shift_path_ants(t_lemin *path)
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

int			tts_advance_ants(int *current_ant, int ant_count,
			t_lemin **room_list)
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

void		tts_print_instruction(int id_ant, t_string room)
{
	write(1, "L", 1);
	ft_putnbr(id_ant);
	write(1, "-", 1);
	ft_putstr(room);
	write(1, " ", 1);
}

void		tts_print_ants(t_lemin **room_list)
{
	size_t	index;
	size_t	jndex;
	t_bool	draw_nothing;

	index = 0;
	draw_nothing = true;
	while (room_list[index])
	{
		jndex = 1;
		while (room_list[index][jndex].room && room_list[index][jndex].id_ant)
		{
			if (room_list[index][jndex].id_ant != -1)
			{
				draw_nothing = false;
				tts_print_instruction(room_list[index][jndex].id_ant,
				room_list[index][jndex].room);
			}
			jndex += 1;
		}
		index += 1;
	}
	draw_nothing == false ? write(1, "\n", 1) : 0;
}

void		tts_show_results(t_file *file, t_data *data,
			t_ind *ices, t_lemin **room_list)
{
	int	current_ant;
	int	ended;

	current_ant = 1;
	ended = 0;
	print_file(file);
	if (!ended && current_ant == 1)
		current_ant -= 1;
	if (room_list[0]->length == 1)
	{
		while (current_ant++ < data->ants)
		{
			tts_print_instruction(current_ant,
			data->r_tab[ices->end->id]->head->name);
			write(1, "\n", 1);
		}
		quit(data, &file, &room_list, 0);
		return ;
	}
	while (current_ant <= data->ants || !ended || (!ended && data->ants == 1))
	{
		ended = tts_advance_ants(&current_ant, data->ants, room_list);
		tts_print_ants(room_list);
	}
	quit(data, &file, &room_list, 0);
}
