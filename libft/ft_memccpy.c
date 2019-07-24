/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 03:41:14 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 02:17:02 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	i = 0;
	u_c = (unsigned char)c;
	u_dst = (unsigned char *)dst;
	u_src = (unsigned char *)src;
	while (i < n)
	{
		if (u_src[i] == u_c)
		{
			u_dst[i] = u_src[i];
			return (u_dst + i + 1);
		}
		u_dst[i] = u_src[i];
		i++;
	}
	if (i == n)
		return (0);
	else
		return (u_dst + 1);
}
