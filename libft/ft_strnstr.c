/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 02:23:24 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/25 22:04:38 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		k = i;
		while (haystack[k + j] == needle[j] && k + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + k));
			j++;
		}
		i++;
	}
	return (0);
}
