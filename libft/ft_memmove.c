/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 02:17:19 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 02:48:34 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	tmp[len];

	if (len > 65535)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}
