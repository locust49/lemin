/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 09:24:01 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/21 09:25:57 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	new = NULL;
	if (s)
	{
		while (s[i])
			i++;
		new = (char *)malloc((1 + i) * sizeof(char));
		if (new)
		{
			while (j < i)
			{
				new[j] = (*f)(j, *(s + j));
				j++;
			}
			new[j] = '\0';
		}
	}
	return (new);
}
