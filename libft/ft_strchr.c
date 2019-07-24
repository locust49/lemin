/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 02:52:31 by slyazid           #+#    #+#             */
/*   Updated: 2018/11/12 18:10:24 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*v;

	i = 0;
	a = (char)c;
	v = (char *)s;
	while (v[i] != '\0')
	{
		if (v[i] == a)
			return (v + i);
		i++;
	}
	if (v[i] == a)
		return (v + i);
	return (0);
}
