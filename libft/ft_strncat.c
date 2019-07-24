/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:16:55 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/21 05:00:42 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	while (s2[i] != '\0' && i < n)
		s1[size++] = s2[i++];
	s1[size] = '\0';
	return (s1);
}
