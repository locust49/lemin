/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:33:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/10 14:32:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	str_iscommand_comment(t_data *data, t_string line)
{
	if (line && *line == '#' && (line + 1) && *(line + 1) == '#')
	{
		if (ft_strequ(line, "##start") && data->info.start == -1)
			data->info.start = 0;
		else if (ft_strequ(line, "##start") && data->info.start == 1)
			return (false);
		if (ft_strequ(line, "##end") && data->info.end == -1)
			data->info.end = 0;
		else if (ft_strequ(line, "##end") && data->info.end == 1)
			return (false);
		if (data->info.end == 0 && data->info.start == 0)
			return (false);
		return (true);
	}
	else if (*line == '#' && *(line + 1) != '#')
		return (true);
	return (false);
}

t_bool	str_iscoords(t_string line)
{
	t_string	tmp;
	t_string	first;
	int			test0;
	int			test1;

	tmp = ft_strrchr(line, ' ') + 1;
	first = ft_strsub(line, 0, (int)(tmp - 1 - line));
	if (tmp && first && ft_ispnum(tmp) && ft_ispnum(first))
	{
		test0 = ft_atoi(tmp);
		test1 = ft_atoi(first);
		if (test0 >= 0 && test1 >= 0)
		{
			first ? free(first) : 0;
			return (true);
		}
	}
	first ? free(first) : 0;
	return (false);
}

t_bool	str_room_link(t_string line)
{
	t_string	tmp;

	if (*line != 'L' && *line != '#' &&
		(((tmp = ft_strchr(line, ' ')) &&
			ft_strwcount(line, ' ') == 3 && tmp && str_iscoords(tmp + 1)) ||
			((tmp = ft_strchr(line, '-')) &&
			ft_strwcount(line, '-') == 2 && *(tmp + 1) && *(tmp + 1) != '-')))
		return (true);
	return (false);
}

t_bool	before_links(t_data data)
{
	if (data.info.end == 1 && data.info.start == 1
		&& data.info.room != -1)
		return (true);
	return (false);
}

t_bool	valid_data(t_data data)
{
	if (data.info.room == 1 && data.info.link == 1 &&
		data.info.start == 1 && data.info.end == 1)
		return (true);
	return (false);
}
