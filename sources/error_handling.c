/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:56:45 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/30 01:27:07 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void	print_usage(char *filename)
{
	ft_putendl_fd("usage:\n\t./lem-in < [valid map]", 2);
	if (filename && ft_strcmp(filename, "No start/end"))
	{
		ft_putstr_fd("\n[TIP]: Please, redirect [", 2);
		ft_putstr_fd(filename, 2);
		ft_putendl_fd("] content", 2);
	}

	exit(0);
}

void	print_error(void)
{
	ft_putendl_fd("Error while opening", 2);
	print_usage(NULL);
	exit(0);
}

void	print_false(int c)
{
	printf("c = [%c]\n", c);
	ft_putendl_fd("Error. Invalid Map.", 2);
	if (c == 'L')
		ft_putendl_fd("Room name start with \"L\"", 2);
	else if (c == '0')
		ft_putendl_fd("Invalid data for ants number", 2);
	else if (c == 'I')
		ft_putstr_fd("Missing Start or End room", 2);
	else if (c == 'x')
		print_error();
	// else if (c == '<')
	//print_usage(NULL);
	exit(0);
}