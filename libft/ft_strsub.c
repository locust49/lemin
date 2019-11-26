/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 10:21:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/11/26 19:30:20 by otel-jac         ###   ########.fr       */
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
