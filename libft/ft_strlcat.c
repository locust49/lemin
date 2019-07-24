/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 02:44:14 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/21 17:08:23 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	id;
	size_t	max;

	i = 0;
	id = ft_strlen(dst);
	max = size - id - 1;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (i < max && src[i] != '\0')
	{
		dst[id + i] = src[i];
		i++;
	}
	dst[id + i] = '\0';
	return (id + ft_strlen(src));
}
