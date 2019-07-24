/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:44:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/24 19:50:20 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int main(int argc, char **argv)
{
	t_map	input;

	if (argc == 1)
		get_input(&input);
	else
		print_usage(argv);
	return (0);
}
