/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 09:26:13 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/21 09:38:30 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	if (s1 && s2)
	{
		if (ft_strlen(s1) >= ft_strlen(s2))
			i = ft_strlen(s1);
		else
			i = ft_strlen(s2);
		while (i > 0)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
			i--;
		}
		return (1);
	}
	return (0);
}
