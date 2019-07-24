/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 04:48:43 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 05:28:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			if (u_s1[i] != u_s2[i])
				return (u_s1[i] - u_s2[i]);
			i++;
		}
		return (u_s1[i - 1] - u_s2[i - 1]);
	}
	else
		return (0);
}
