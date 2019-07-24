/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 07:49:24 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:22:26 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_minint(int nb)
{
	int		i;
	char	*min;

	i = 0;
	min = "-2147483648";
	if (nb == -2147483648)
	{
		while (min[i] != '\0')
			ft_putchar(min[i++]);
	}
}

void		ft_putnbr(int n)
{
	int		na;

	if (n == -2147483648)
		ft_put_minint(n);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
		{
			na = n % 10;
			ft_putnbr(n / 10);
			ft_putchar(na + '0');
		}
		else
			ft_putchar(n + '0');
	}
}
