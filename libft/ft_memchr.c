/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 02:48:44 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 03:56:42 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_s;

	i = 0;
	u_s = (unsigned char*)s;
	while (i < n)
	{
		if (u_s[i] == (unsigned char)c)
			return ((void*)u_s + i);
		i++;
	}
	return (NULL);
}
