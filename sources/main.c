/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:34:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/12 16:46:19 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	debug(void)
{
	ft_putendl_fd("\x1b[33:0mDEBUG\x1b[0:0m", 2);
}

void	initialize_data(t_data *data, t_ind *ices)
{
	long long	i;

	i = -1;
	data->ants = -1;
	data->rooms = 0;
	data->info.room = -1;
	data->info.link = -1;
	data->info.start = -1;
	data->info.end = -1;
	ices->end = NULL;
	ices->head = NULL;
	ices->start = NULL;
	ices->tail = NULL;
	while (++i < MAX_NODE)
	{
		data->r_tab[i] = (t_ind*)malloc(sizeof(t_ind));
		(data->r_tab[i])->head = NULL;
	}
}

void	print_data(t_data *data)
{
	printf(" data->ants = %d\n", data->ants);
	printf(" data->info.room = %d\n", data->info.room);
	printf(" data->info.link = %d\n", data->info.link);
	printf(" data->info.start = %d\n", data->info.start);
	printf(" data->info.end = %d\n", data->info.end);
}

void	quit(void)
{
	ft_putendl_fd("\x1b[31:0mERROR\x1b[0:0m", 2);
	exit(-1);
}

void	get_ants(t_data *data, t_string line)
{
	if (ft_strlen(line) >= 10 && ft_strcmp(line, "2147483647") > 0)
		quit();
	data->ants = ft_atoi(line);
	// printf("ants = %d\n", data->ants);
	if (data->ants <= 0)
		quit();
}

void	store_room(t_data *data, t_string line, t_ind *ices)
{
	data->rooms += 1;
	if (data->info.start == 0 && data->info.end != 0)
		store_start(line, ices, data);
	else if (data->info.end == 0 && data->info.start != 0)
		store_end(line, ices, data);
	else if (data->info.room == 0 || data->info.room == -1)
		add_room(line, data);
	else
		quit();
}

void	get_graph(t_data *data, t_string line, t_ind *ices)
{
	if (str_iscomment(line) == false
		&& str_iscommand(data, line) == false
		&& str_room_link(line) == true)
	{
		if (ft_strchr(line, ' '))
		{
			data->info.room == -1 ? data->info.room = 0 : 0;
			store_room(data, line, ices);
		}
		if (ft_strchr(line, '-') && !ft_strchr(line, ' ')
			&& before_links(*data) == true)
		{
			data->info.room == 0 ? data->info.room = 1 : 0;
			data->info.link == -1 ? data->info.link = 0 : 0;
			store_link(data, line);
		}
		else if ((ft_strchr(line, '-')
		&& ((before_links(*data) == false) || ft_strchr(line, ' '))))
			quit();
	}
	else if (str_iscomment(line) == false && str_iscommand(data, line) == false
		&& str_room_link(line) == false)
		quit();
	else if (str_iscomment(line) == true || str_iscommand(data, line) == true)
		;
		//ft_putendl("command or comment");
}

/*
**	// ft_putendl("***********after************");
**	// print_data(data);
**	// ft_putendl("*************************");
*/

/*
**	// print_rooms(&data, 1);
**	// printf("nbr of rooms = %d\n", data.rooms);
**	// print_rooms(rooms);
**	// print_ices(&ices);
*/

void	free_room(t_room *room)
{
	if (room)
	{
		room->name ? free(room->name) : 0;
		room->links ? free_links(&(room->links)) : 0;
		free(room);
	}
}

void	free_data(t_data *data)
{
	int		i;
	t_room	*tmp;

	if (data)
	{
		if (*(data->r_tab))
		{
			i = 0;
			while (i < MAX_NODE)
			{
				if (data->r_tab[i]->head && !data->r_tab[i]->head->next)
					free_room(data->r_tab[i]->head);
				else
					while (data->r_tab[i]->head)
					{
						tmp = data->r_tab[i]->head;
						data->r_tab[i]->head = data->r_tab[i]->head->next;
						free_room(tmp);
					}
				free(data->r_tab[i]);
				i++;
			}
		}
	}
}

int		main(void)
{
	int			gnl;
	t_string	line;
	t_file		*file;
	t_data		data;
	t_ind		ices;
	t_heap		heap;

	file = NULL;
	initialize_data(&data, &ices);
	gnl = 0;
	while (get_next_line(0, &line))
	{
		gnl += 1;
		if (gnl == 1)
			str_ispnum(line) ? get_ants(&data, line) : quit();
		else if (!ft_strcmp(line, ""))
			break ;
		else
			get_graph(&data, line, &ices);
		add_line(&file, line);
		line ? free(line) : 0;
	}
	line ? free(line) : 0;
	//valid_data(data) ? print_file(file) : quit();
	// get_next_node(&data, &ices);
	int i = -1;
	heap.nopath = 1;
	while (heap.nopath)
	{
		i++;
		printf("\x1b[31:0mbfs %d\x1b[0:0m\n", i);
		// printf("queue = %p\n", heap.queue);
		bfs(&ices, &heap);
		// print_plist(&data);
		// print_ices(&ices);
		// rupdate_graph(&ices, ices.end);
		update_graph(&ices);
		// get_groups(&ices, &heap);
		// print_short(&ices);
	}
	// free_visited(&heap);
	free_data(&data);
	free_file(&file);
}

/*
**	free before quit if !valid
*/
