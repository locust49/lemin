/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:56:45 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/25 19:45:52 by slyazid          ###   ########.fr       */
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
	if (!ft_strcmp(filename, "No start/end"))
	{
		ft_putstr_fd("\n[TIP]: [", 2);
		ft_putstr_fd(filename, 2);
		ft_putendl_fd("]", 2);
	}
	exit(0);
}

void	print_error(void)
{
	ft_putendl_fd("Error while opening", 2);
	print_usage(NULL);
	exit(0);
}

void	print_false(void)
{
	ft_putendl_fd("Error. Invalid Map.", 2);
	//print_usage(NULL);
	exit(0);
}