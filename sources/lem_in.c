/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:10:13 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/02 17:15:15 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	initialize_data(t_data *data, t_ind *ices,
		t_file **file, t_lemin ***room_list)
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
	*file = NULL;
	*room_list = NULL;
	while (++i < MAX_NODE)
	{
		data->r_tab[i] = (t_ind*)malloc(sizeof(t_ind));
		(data->r_tab[i])->head = NULL;
	}
}

t_bool	get_ants(t_data *data, t_string line)
{
	if (ft_strlen(line) >= 10 && ft_strcmp(line, "2147483647") > 0)
	{
		ft_memdel((void**)&line);
		return (false);
	}
	if (ft_atoi(line) <= 0)
	{
		ft_memdel((void**)&line);
		return (false);
	}
	data->ants = ft_atoi(line);
	return (true);
}

t_bool	store_room(t_data *data, t_string line, t_ind *ices)
{
	long long add;

	add = 0;
	data->rooms += 1;
	if (data->info.start == 0 && data->info.end != 0)
		store_start(line, ices, data);
	else if (data->info.end == 0 && data->info.start != 0)
		store_end(line, ices, data);
	else if (data->info.room == 0 || data->info.room == -1)
	{
		if (((add = add_room(line, data)) < 0))
			return (false);
	}
	return (true);
}

t_bool	get_graph(t_data *data, t_string line, t_ind *ices)
{
	if (!str_iscommand_comment(data, line) &&
		str_room_link(line))
	{
		if (ft_xor(ft_strchr(line, ' '), ft_strchr(line, '-')))
		{
			if (ft_strchr(line, ' '))
			{
				data->info.room == -1 ? data->info.room = 0 : 0;
				return (store_room(data, line, ices));
			}
			if (ft_strchr(line, '-'))
			{
				if (!before_links(*data))
					return (false);
				data->info.room == 0 ? data->info.room = 1 : 0;
				data->info.link == -1 ? data->info.link = 0 : 0;
				return (store_link(data, line));
			}
		}
		else
			return (false);
	}
	else if (str_iscommand_comment(data, line))
		return (true);
	return (false);
}

t_lemin	**dispatch_graph(t_ind *ices, t_data *data)
{
	t_htgroup	*groups;
	t_heap		heap;
	t_bool		path_found;
	t_lemin		**list;

	if (!(groups = (t_htgroup *)malloc(sizeof(t_htgroup))))
		exit(-1);
	path_found = false;
	groups->head = NULL;
	groups->tail = NULL;
	heap.nopath = 1;
	while (heap.nopath)
	{
		bfs(ices, &heap);
		if (heap.nopath == 0)
			break ;
		path_found = true;
		update_graph(ices);
		get_groups(ices, data, &groups);
	}
	list = path_found ? convert_chosen_group(choose_group(groups->head)) : 0;
	groups && groups->head ? free_groups(&(groups->head)) : 0;
	!list ? free_groups(&groups->head) : 0;
	return (list);
}
