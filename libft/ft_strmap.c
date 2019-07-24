/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 09:08:12 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/21 09:23:35 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				new[j] = (*f)(*(s + j));
				j++;
			}
			new[j] = '\0';
		}
	}
	return (new);
}
