/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:21:16 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 22:17:31 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	if (len == 0 || (s1[0] == '\0' && s2[0] == '\0'))
		return (0);
	while (us1[i] == us2[i] && i < len)
	{
		if (!us1[i] || !us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (i == len)
		return (us1[i - 1] - us2[i - 1]);
	else
		return (us1[i] - us2[i]);
}
