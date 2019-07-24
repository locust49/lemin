/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 05:16:02 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/24 23:04:58 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digit_count(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	int		tmp;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	i = ft_digit_count(n);
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	if (!(nbr = (char*)malloc((1 + i) * sizeof(char))))
		return (NULL);
	nbr[i] = '\0';
	while (i > 0)
	{
		nbr[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (tmp < 0)
		nbr[0] = '-';
	return (nbr);
}
