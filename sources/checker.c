/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:33:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/30 18:12:36 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	str_ispnum(t_string line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (false);
	return (true);
}

t_bool	str_iscomment(t_string line)
{
	if (*line == '#' && *(line + 1) != '#')
		return (true);
	return (false);
}

/*
** || (!ft_strequ(line, "##start") && !ft_strequ(line, "##end")))
*/

t_bool	str_iscommand(t_data *data, t_string line)
{
	if (*line == '#' && *(line + 1) == '#')
	{
		if (ft_strequ(line, "##start") && data->info.start == -1)
			data->info.start = 0;
		if (ft_strequ(line, "##end") && data->info.end == -1)
			data->info.end = 0;
		if (data->info.end == 0 && data->info.start == 0)
			quit();
		return (true);
	}
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
	if (tmp && first && str_ispnum(tmp) && str_ispnum(first))
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

/*
** change line 89 : *(tmp + 1) != '-') with check if room exists;
*/

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

/*
** valid data need more conditions about if the graph is linked or not ;)
*/

t_bool	valid_data(t_data data)
{
	if (before_links(data) == true && data.info.link == 0)
		return (true);
	return (false);
}
