/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:34:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/27 06:58:39 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	debug(void)
{
	ft_putendl_fd("\x1b[33:0mDEBUG\x1b[0:0m", 2);
}

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

// void	print_data(t_data *data)
// {
// 	printf(" data->ants = %d\n", data->ants);
// 	printf(" data->info.room = %d\n", data->info.room);
// 	printf(" data->info.link = %d\n", data->info.link);
// 	printf(" data->info.start = %d\n", data->info.start);
// 	printf(" data->info.end = %d\n", data->info.end);
// }

void	quit(t_data *data, t_file **file, t_lemin ***room_list)
{
	room_list && *room_list ? free_room_list(room_list) : 0;
	data ? free_data(data) : 0;
	file ? free_file(file) : 0;
	ft_putendl_fd("ERROR", 1);
	// ft_putendl_fd("\x1b[31:0mERROR\x1b[0:0m", 2);
	exit(-1);
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
	if (str_iscomment(line) == false
		&& str_iscommand(data, line) == false
		&& str_room_link(line) == true)
	{
		if (ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		{
			data->info.room == -1 ? data->info.room = 0 : 0;
			if ((store_room(data, line, ices) == false))
				return (false);
		}
		if (ft_strchr(line, '-') && !ft_strchr(line, ' ')
			&& before_links(*data) == true)
		{
			data->info.room == 0 ? data->info.room = 1 : 0;
			data->info.link == -1 ? data->info.link = 0 : 0;
			if (store_link(data, line) == false)
				return (false);
		}
		else if (ft_strchr(line, '-') && (ft_strchr(line, ' ')))
			return (false);
		else if ((ft_strchr(line, '-')
		&& ((before_links(*data) == false) || ft_strchr(line, ' '))))
		{
			// printf("get_graph 1\n");
			return (false);
		}
	}
	else if (str_iscomment(line) == false && str_iscommand(data, line) == false
		&& str_room_link(line) == false)
	{
		// printf("get_graph 2\nline %s\n", line);
		return (false);
	}
	else if (str_iscomment(line) == true || str_iscommand(data, line) == true)
		return (true);
	else
	{
		printf("hi\n");
	}
	return (true);
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

void	free_parents(t_htparent **parents)
{
	t_parent *tmp;
    t_parent *del;

	del = (*parents)->head;
	while (del)
	{
		tmp = del->next;
        ft_memdel((void**)&del);
        del = tmp;
	}
	ft_memdel((void**)&del);
	// ft_memdel((void**)parents);
}

void	free_path(t_path **path)
{
	t_path *tmp;
    t_path *del;

	del = (*path);
	while (del)
	{
		tmp = del->next;
        free_parents(&(del->paths));
		ft_memdel((void**)&(del->paths));
		ft_memdel((void**)&del);
        del = tmp;
	}
}

void	free_groups(t_group **group)
{
	t_group *tmp;
	t_group	*del;

	del = (*group);
	while (del)
	{
        tmp = del->next;
		free_path(&(del->path->head));
		ft_memdel((void**)&del->path);
        ft_memdel((void**)&del);
		del = tmp;
	}
}


// void	free_group(t_group **group)
// {
// 	t_parent	*parent;
// 	t_parent	*tmp_parent;
// 	t_group		*tmp_group;

// 	while (group && *group)
// 	{
// 		tmp_group = *group;
// 		parent = tmp_group->path->head->paths->head;
// 		while (parent)
// 		{
// 			tmp_parent = parent;
// 			free_room(tmp_parent->room);
// 			ft_memdel((void**)&tmp_parent);
// 			parent = parent->next;
// 		}
// 		*group = (*group)->next;
// 		ft_memdel((void**)&tmp_group);
// 	}
// 	ft_memdel((void**)group);
// }

// void	free_heap(t_heap *heap)
// {
	
// }

void	free_room_list(t_lemin ***list)
{
	int		index;
	t_lemin	**tmp;

	tmp = *list;
	index = 0;
	while (tmp[index])
	{
		free(tmp[index]);
		index += 1;
	}
	ft_memdel((void**)list);
}

t_lemin	**dispatch_graph(t_ind *ices, t_data *data)
{
	t_htgroup	*groups;
	t_heap		heap;
	t_group		*chosen;
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
	if (path_found == false)
	{
		groups && groups->head? free_groups(&(groups->head)) : 0;
		groups ? free(groups) : 0;
		return (NULL);
	}
	chosen = choose_group(groups->head);
	list = convert_chosen_group(chosen);
	free_groups(&(groups->head));
	free(groups);
	return (list);
}

/*
**	quit will take data, ices and file as parameters to free in case of error;
*/

int		main(void)
{
	t_string	line;
	t_file		*file;
	t_data		data;
	t_ind		ices;
	t_lemin		**room_list;
	t_bool		g;

	g = true;
	initialize_data(&data, &ices, &file, &room_list);
	if (get_next_line(0, &line) <= 0 || !str_ispnum(line) ||
		!get_ants(&data, line))
		quit(&data, &file, &room_list);
	add_line(&file, line);
	ft_memdel((void**)&line);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (((g = get_graph(&data, line, &ices)) == false))
			break ;
		add_line(&file, line);
		line ? ft_memdel((void**)&line) : 0;
	}
	data.info.link == 0 ? data.info.link = 1 : 0;
	line ? ft_memdel((void**)&line) : 0;
	!g ? quit(&data, &file, &room_list) : 0;
	valid_data(data) ? room_list = dispatch_graph(&ices, &data) : 0;
	
	if (!room_list || !valid_data(data))
		quit(&data, &file, &room_list);
	print_file(file);
	tts_show_results(data.ants, room_list);
	free_room_list(&room_list);
	free_data(&data);
	free_file(&file);
	return (0);
}

/*
**	free before quit if !valid
**	free_visited(&heap);
*/
