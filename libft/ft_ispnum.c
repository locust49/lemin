/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:13:35 by slyazid           #+#    #+#             */
/*   Updated: 2019/12/10 14:32:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_ispnum(t_string line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (false);
	return (true);
}
