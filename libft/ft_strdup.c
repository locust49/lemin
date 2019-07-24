/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 01:46:15 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:43:37 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*sres;

	sres = NULL;
	len = ft_strlen(s1);
	sres = (char *)malloc(len + 1 * sizeof(char));
	if (!sres)
		return (0);
	else
		sres = ft_strcpy(sres, (char *)s1);
	return (sres);
}
