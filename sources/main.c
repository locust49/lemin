/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:34:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/10 14:32:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_string	line;
	t_file		*file;
	t_data		data;
	t_ind		ices;
	t_lemin		**room_list;

	initialize_data(&data, &ices, &file, &room_list);
	if (get_next_line(0, &line) <= 0 || !ft_ispnum(line)
		|| !get_ants(&data, line))
		quit(&data, &file, &room_list, 1);
	add_line(&file, line);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, ""))
			break ;
		!get_graph(&data, line, &ices) ? quit(&data, &file, &room_list, 1) : 0;
		add_line(&file, line);
	}
	line ? ft_memdel((void**)&line) : 0;
	data.info.link == 0 ? data.info.link = 1 : 0;
	valid_data(data) ? room_list = dispatch_graph(&ices, &data) :
	quit(&data, &file, &room_list, 1);
	(!room_list || !valid_data(data)) ? quit(&data, &file, &room_list, 1) : 0;
	tts_show_results(file, &data, &ices, room_list);
	return (0);
}
