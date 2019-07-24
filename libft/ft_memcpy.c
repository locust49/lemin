/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 03:22:02 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 02:39:49 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	i = 0;
	u_dst = (unsigned char *)dst;
	u_src = (unsigned char *)src;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		i++;
	}
	return (u_dst);
}
