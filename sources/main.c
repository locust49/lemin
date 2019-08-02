/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:44:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/31 03:33:06 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int main(int argc, char** argv)
{
	t_input	*input;

	input = NULL;
	if (argc == 1)
		get_input(input);
	else
		print_usage(argv[1]);
	return (0);
}
