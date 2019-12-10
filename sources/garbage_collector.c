/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:07:33 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/02 17:01:51 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	ft_memdel((void**)&group);
}

void	free_room_list(t_lemin ***list)
{
	int		index;
	t_lemin	**tmp;

	tmp = *list;
	index = 0;
	if (tmp)
	{
		while (tmp[index])
		{
			free(tmp[index]);
			index += 1;
		}
	}
	ft_memdel((void**)list);
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
