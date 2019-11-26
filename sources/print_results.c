/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/26 19:33:53 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void		init_chosen(int index, t_path *tmp,
// t_group *head, t_lemin **chosen)
// {
// 	chosen[index] = (t_lemin *)malloc(sizeof(t_lemin) *
// 					(head->biggest_path_node));
// 	chosen[index]->length = tmp->paths->total_node;
// 	chosen[index]->virtual_len = 0;
// 	chosen[index]->blocked = 0;
// }

// t_lemin		**convert_chosen_group(t_group *head)
// {
// 	t_lemin		**chosen;
// 	t_path		*tmp;
// 	int			index;
// 	int			i_room;

// 	index = -1;
// 	chosen = (t_lemin**)malloc(sizeof(t_lemin*) * (head->path_num + 1));
// 	tmp = head->path->head;
// 	while (++index < head->path_num)
// 	{
// 		i_room = 0;
// 		init_chosen(index, tmp, head, chosen);
// 		while (i_room < head->biggest_path_node)
// 		{
// 			(chosen[index][i_room]).room = 	tmp->paths->head->room->name;
// 			chosen[index][i_room].id_ant = -1;
// 			tmp->paths->head ? tmp->paths->head = tmp->paths->head->next : 0;
// 			i_room += 1;
// 		}
// 		chosen[index][i_room].room = NULL;
// 		tmp = tmp->next;
// 	}
// 	chosen[index] = NULL;
// 	return (chosen);
// }

char		**convert_path(t_path *path, int path_node)
{
	t_parent	*tmp;
	char		**room;
	int			j;

	if (!(room = (char **)malloc(sizeof(char*) * (path_node + 1))))
		exit(-1);
	j = 0;
	tmp = path->paths->head;
	while (tmp)
	{
		if (!(room[j] = ft_strsub(tmp->room->name, 0, ft_strlen(tmp->room->name))))
			exit(-1);
		j++;
		tmp = tmp->next;
	}
	room[j] = NULL;
	return (room);
}

char		***convert_chosen_group(t_group *head)
{
	char		***room;
	t_path		*ptmp;
	t_parent	*tmp;
	int			i;

	if (!(room = (char ***)malloc(sizeof(char**) * (head->path_num + 1))))
		exit(-1);
	i = 0;
	ptmp = head->path->head;
	while (i < head->path_num)
	{
		room[i] = convert_path(ptmp, head->biggest_path_node);
		ptmp = ptmp->next;
		i++;
	}
	room[head->path_num] = NULL;
	return (room);
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

void	tts_simulate_moves(int *current_ant, int ant_count, t_lemin **room_list)
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
		while (room_list[index][jndex].room && room_list[index][jndex].id_ant)
		{
			if (room_list[index][jndex].id_ant != -1)
			{
				draw_nothing = false;
				write(1, "L", 1);
				ft_putnbr(room_list[index][jndex].id_ant);
				write(1, "-", 1);
				ft_putstr(room_list[index][jndex].room);
				write(1, " ", 1);
			}
			jndex += 1;
		}
		index += 1;
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
