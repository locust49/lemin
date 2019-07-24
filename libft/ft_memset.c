/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:18:29 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/15 22:52:37 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	uc;

	i = 0;
	str = (char*)b;
	uc = (unsigned char)c;
	while (i < len)
	{
		*(str + i) = uc;
		i++;
	}
	return (b);
}
