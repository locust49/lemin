/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:57:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/30 01:27:16 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

char	*ft_roomname(char *line)
{
	char	*name;

	name = ft_strsub(line, 0, (size_t)(ft_strchr(line, ' ') - line));
	return (name);
}

void	get_ants(int *number, char *line, int *row)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] && !ft_isdigit(line[i]))
			print_false('0');
	*number = ft_atoi(line);
	*row = 1;
}

void	ft_strore_inout(t_map *in, char *line, int *row)
{
	if (!ft_strcmp(line, "##start"))
	{	
		get_next_line(0, &line);
		ft_putendl(line);
		(*line == 'L') ? print_false('L') : 0;
		in->inout[0].id = 0;
		in->inout[0].name = ft_roomname(line);
		*row += 1;
	}
	if (!ft_strcmp(line, "##end"))
	{	
		get_next_line(0, &line);
		ft_putendl(line);
		(*line == 'L') ? print_false('L') : 0;
		in->inout[1].id = 1;
		in->inout[1].name = ft_roomname(line);
		*row += 1;
	}
}

void	get_input(t_map *in)
{
	char	*line;
	int		row;
	int		gnl;

	row = 0;
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		ft_putendl(line);
		row == 0 ? get_ants(&(in->ants), line, &row) : 0;
		(*line == 'L') ? print_false('L') : 0;
		ft_strore_inout(in, line, &row);
		if (*line == '#' && (ft_strcmp(line, "##end") || ft_strcmp(line, "##start")))
			continue ;
		in->next = 0;
	}
	ft_putchar('\n');
	row != 3 ? print_false('I') : 0;
	gnl == -1 ? print_false('x') : 0;
	printf("Valid map");
}
