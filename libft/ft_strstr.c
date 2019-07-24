/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:18:57 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 23:02:56 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	if (haystack[0] == '\0')
		return (NULL);
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (haystack[k + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + k));
		}
		i++;
	}
	return (NULL);
}
