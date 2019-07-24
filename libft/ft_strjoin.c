/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 10:40:04 by slyazid           #+#    #+#             */
/*   Updated: 2018/11/14 22:27:05 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = ft_strlen((char *)s1);
	while (s2[j++] != '\0')
		i++;
	if (!(join = (char *)malloc(i + 1)))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
