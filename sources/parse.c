/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:57:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/25 20:57:16 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

// t_bool	valid_file(char *filename)
// {
// 	int     fd;
// 	int     err;
// 	char    *line;

// 	fd = open(filename, O_RDONLY);
// 	err = get_next_line(fd, &line);
// 	if (!fd || err < 0)
// 		return (false);
// 	return (true);
// }
char	*ft_roomname(char *line)
{
	char	*name;

	name = ft_strsub(line, 0, (size_t)(ft_strchr(line, ' ') - line));
	return (name);
}

void	ft_strore_inout(t_map *in, char *line, int *row)
{
	if (!ft_strcmp(line, "##start"))
	{	
		get_next_line(0, &line);
		if (*line == 'L')
			print_false();
		in->inout[0].id = 0;
		in->inout[0].name = ft_roomname(line);
		*row += 1;
	}
	if (!ft_strcmp(line, "##end"))
	{	
		get_next_line(0, &line);
		if (*line == 'L')
			print_false();
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
		row == 0 ? in->ants = ft_atoi(line) : 0;
		if (*line == 'L')
			print_false();
		ft_strore_inout(in, line, &row);
		if (*line == '#' && (ft_strcmp(line, "##end") || ft_strcmp(line, "##start")))
			continue ;
		in->next = 0;
	}
	printf("row = %d\n", row);
	row != 2 ? print_usage("No start/end") : 0;
	gnl == -1 ? print_error() : 0;
	printf("Valid map");
}
