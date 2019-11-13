/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:11:46 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/11 09:09:35 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// t_link	*new_link(t_data *data, int link_id)
// {
// 	t_link	*new;

// 	if (!(new = (t_link*)malloc(sizeof(t_link))))
// 		exit(-1);
// 	new->to = data->r_tab[link_id]->head;
// 	new->flow = 1;
// 	new->next = NULL;
// 	return (new);
// }

// void	add_link(t_link **links, t_data *data, long long link_id)
// {
// 	if (!*links)
// 	{
// 		(*links) = new_link(data, link_id);
// 		(*links)->tail = *links;
// 	}
// 	else
// 	{
// 		(*links)->tail->next = new_link(data, link_id);
// 		(*links)->tail = (*links)->tail->next;
// 	}
// }

// void	set_link_room(t_data *data, long long head_id,
// 		long long link_id, t_string head)
// {
// 	t_room *tmp;

// 	if ((data->r_tab[head_id]->head) && !(data->r_tab[head_id]->head->next))
// 		add_link(&(data->r_tab[head_id]->head->links), data, link_id);
// 	else if (data->r_tab[head_id]->head && data->r_tab[head_id]->head->next)
// 	{
// 		tmp = (data->r_tab[head_id])->head;
// 		while (tmp)
// 		{
// 			if (ft_strequ(tmp->name, head))
// 				add_link(&(tmp->links), data, link_id);
// 			tmp = tmp->next;
// 		}
// 	}
// }

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
