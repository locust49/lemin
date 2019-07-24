/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 10:21:43 by slyazid           #+#    #+#             */
/*   Updated: 2018/11/12 18:12:12 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(sub_s = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len--)
	{
		sub_s[i] = s[i + start];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
