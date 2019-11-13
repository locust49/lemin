/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:11:46 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/13 17:29:09 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*new_link(t_room *room)
{
	t_link	*new;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	new->to = room;
	new->flow = 1;
	new->next = NULL;
	return (new);
}

void	add_link(t_link **links, t_room *room)
{
	if (!*links)
	{
		(*links) = new_link(room);
		(*links)->tail = *links;
	}
	else
	{
		(*links)->tail->next = new_link(room);
		(*links)->tail = (*links)->tail->next;
	}
}

t_room	*find_node(long long link_id, char *name, t_data *data)
{
	t_room *tmp;

	tmp = data->r_tab[link_id]->head;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	store_link(t_data *data, t_string line)
{
	t_string	first;
	t_string	second;
	t_room		*room1;
	t_room		*room2;

	second = ft_strchr(line, '-') + 1;
	first = ft_strsub(line, 0, second - (line + 1));
	room1 = find_node(get_hash_id(first), first, data);
	room2 = find_node(get_hash_id(second), second, data);
	if (!room1 || !room2)
	{
		free(first);
		quit();
	}
	add_link(&(room1->links), room2);
	add_link(&(room2->links), room1);
	free(first);
}

void	free_links(t_link **links)
{
	t_link	*tmp;

	if (links && *links)
	{
		while (*links)
		{
			tmp = *links;
			*links = (*links)->next;
			free(tmp);
		}
	}
}
