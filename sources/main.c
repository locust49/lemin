/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:34:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/26 20:24:23 by otel-jac         ###   ########.fr       */
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
	{
		printf("store room\n");
		quit();
	}
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
			{
				printf("get_graph 1\n");
				quit();
				}
	}
	else if (str_iscomment(line) == false && str_iscommand(data, line) == false
		&& str_room_link(line) == false)
		{
			printf("get_graph 2\nline %s\n", line);
			quit();
			}
	else if (str_iscomment(line) == true || str_iscommand(data, line) == true)
		;
}

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

char	***free_room_list(char ***room_list)
{
	int			i;
	int			j;

	i = 0;
	if (room_list[i] == NULL)
		exit(-1);
	while (room_list[i])
	{
		j = 0;
		while (room_list[i][j])
		{
			free(room_list[i][j]);
			j++;
		}
		free(room_list[i]);
		i++;
	}
	free(room_list);
	return (room_list);
}

// void	free_room_list(t_lemin ***list)
// {
// 	int		index;
// 	t_lemin	**tmp;

// 	tmp = *list;
// 	index = 0;
// 	while (tmp[index])
// 	{
		// free(tmp[index]->room);
// 		free(tmp[index]);
// 		index += 1;
// 	}
// 	free(*list);
// }

int		main(int argc, char **argv)
{
	int			gnl;
	t_string	line;
	t_file		*file;
	t_data		data;
	t_ind		ices;
	t_heap		heap;
	t_htgroup   *groups;
	int			i;
	t_group		*chosen;
	char 		***room_list;
	int			fd;

	file = NULL;
	initialize_data(&data, &ices);
	gnl = 0;
	while (get_next_line(0, &line) > 0)
	{
		gnl += 1;
		if (gnl == 1)
			str_ispnum(line) ? get_ants(&data, line) : quit();
		else if (!ft_strcmp(line, ""))
			break ; // test if valid break else quit;
		else
			get_graph(&data, line, &ices);
		add_line(&file, line);
		line ? free(line) : 0;
	}
	line ? free(line) : 0;
	print_file(file);
	if (gnl)
		{
			if (!(groups = (t_htgroup *)malloc(sizeof(t_htgroup))))
			exit(-1);
		groups->head = NULL;
		groups->tail = NULL;
		i = 0;
		heap.nopath = 1;
		while (heap.nopath)
		{
			bfs(&ices, &heap);
			if (heap.nopath == 0)
				break;
			i++;
			update_graph(&ices);
			get_groups(&ices, &data, &groups);
		}
		if (i == 0)
		{
			printf("No path found\n");
			quit();
		}
		chosen = choose_group(groups->head);
		room_list = convert_chosen_group(chosen);
		print_room_list(room_list);
		free_room_list(room_list);
		free_groups(&(groups->head));
		free(groups);
		free_data(&data);
		free_file(&file);
		return (0);
		}
		else
		{
			quit();
		}
}
