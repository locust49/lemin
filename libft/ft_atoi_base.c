/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 05:39:58 by slyazid           #+#    #+#             */
/*   Updated: 2019/07/12 17:24:28 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_hex_to_dec(int c)
{
	int		i;
	char	*num;

	num = ft_strdup("0123456789ABCDEF");
	i = -1;
	while (++i <= 15)
		if (num[i] == c)
		{
			free(num);
			return (i);
		}
	free(num);
	return (-1);
}

long		ft_atoi_base(const char *str, int base)
{
	int		i;
	long	nbr;
	int		sign;

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
	if (!ft_isdigit(str[i]) && !ft_isalpha(str[i]))
		return (0);
	else
	{
		while (ft_isdigit(str[i]) || ft_isalpha(str[i]))
			nbr = nbr * base + ft_hex_to_dec(str[i++]);
		return (nbr * sign);
	}
	return (0);
}
