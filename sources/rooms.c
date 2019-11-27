/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:06:01 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/27 06:48:14 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*new_room(t_string line, int thisid)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		exit(-1);
	new->id = thisid;
	new->visited = 0;
	new->capacity = 1;
	new->parent = NULL;
	new->parents = NULL;
	new->name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	new->links = NULL;
	new->next = NULL;
	return (new);
}

long long	add_room(t_string line, t_data *data)
{
	long long	hash_id;
	t_string	name;
	t_room		*found;

	found = NULL;
	name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	hash_id = get_hash_id(name);
	if (!(data->r_tab[hash_id]->head))
	{
		data->r_tab[hash_id]->head = new_room(line, hash_id);
		data->r_tab[hash_id]->tail = data->r_tab[hash_id]->head;
	}
	else
	{
		if (!(found = find_node(hash_id, name, data)))
		{
			data->r_tab[hash_id]->tail->next = new_room(line, hash_id);
			data->r_tab[hash_id]->tail = data->r_tab[hash_id]->tail->next;
			name ? free(name) : 0;
			return (hash_id);
		}
		name ? free(name) : 0;
		return (-1);
	}
	name ? free(name) : 0;
	return (hash_id);
}

void		store_start(t_string line, t_ind *ind, t_data *data)
{
	long long	start_id;

	data->info.start = 1;
	start_id = add_room(line, data);
	if (start_id < 0)
		return ;
	ind->start = data->r_tab[start_id]->tail;
}

void		store_end(t_string line, t_ind *ind, t_data *data)
{
	long long	end_id;

	data->info.end = 1;
	end_id = add_room(line, data);
	if (end_id < 0)
		return ;
	ind->end = data->r_tab[end_id]->tail;
}
