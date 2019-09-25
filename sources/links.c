/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:11:46 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/22 19:34:52 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*new_link(t_data *data, int link_id)
{
	t_link	*new;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	new->to = data->r_tab[link_id]->head;
	new->next = NULL;
	return (new);
}

void	add_link(t_link **links, t_data *data, long long link_id)
{
	if (!*links)
	{
		(*links) = new_link(data, link_id);
		(*links)->tail = *links;
	}
	else
	{
		(*links)->tail->next = new_link(data, link_id);
		(*links)->tail = (*links)->tail->next;
	}
}

void	set_link_room(t_data *data, long long head_id,
		long long link_id, t_string head)
{
	t_room *tmp;

	if ((data->r_tab[head_id]->head) && !(data->r_tab[head_id]->head->next))
		add_link(&(data->r_tab[head_id]->head->links), data, link_id);
	else if (data->r_tab[head_id]->head && data->r_tab[head_id]->head->next)
	{
		tmp = (data->r_tab[head_id])->head;
		while (tmp)
		{
			if (ft_strequ(tmp->name, head))
				add_link(&(tmp->links), data, link_id);
			tmp = tmp->next;
		}
	}
}

void	store_link(t_data *data, t_string line)
{
	t_string	first;
	t_string	second;
	long long	id_first;
	long long	id_second;

	second = ft_strchr(line, '-') + 1;
	first = ft_strsub(line, 0, second - (line + 1));
	id_first = get_hash_id(first);
	id_second = get_hash_id(second);
	set_link_room(data, id_first, id_second, first);
	set_link_room(data, id_second, id_first, second);
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
