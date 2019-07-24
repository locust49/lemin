/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:20:55 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/20 21:43:27 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (us1[i] == us2[i] && us1[i] && us2[i])
		i++;
	if (us1[i] != us2[i])
		return (us1[i] - us2[i]);
	else
		return (0);
}
