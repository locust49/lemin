/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:06:24 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/04 15:30:03 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	quit(t_data *data, t_file **file, t_lemin ***room_list, int error)
{
	room_list ? free_room_list(room_list) : 0;
	data ? free_data(data) : 0;
	file ? free_file(file) : 0;
	error ? ft_putendl_fd("ERROR", 2) : 0;
	error ? exit(-1) : 0;
}
