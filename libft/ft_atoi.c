/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:43:59 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 03:44:04 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	else
	{
		while (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * 10 + (str[i++] - '0');
		return (nbr * sign);
	}
	return (0);
}
