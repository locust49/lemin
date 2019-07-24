/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 07:53:37 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/24 23:43:56 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_minint_fd(int nb, int fd)
{
	int		i;
	char	*min;

	i = 0;
	min = "-2147483648";
	if (nb == -2147483648)
	{
		while (min[i] != '\0')
			ft_putchar_fd(min[i++], fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		na;

	if (n == -2147483648)
		ft_put_minint_fd(n, fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
		{
			na = n % 10;
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(na + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
