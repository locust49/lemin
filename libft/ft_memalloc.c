/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 08:14:03 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/21 08:35:04 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*mem;
	size_t	i;

	i = 0;
	mem = (int *)malloc(size * sizeof(int));
	if (!mem)
		return (NULL);
	while (i < size)
	{
		*(mem + i) = 0;
		i++;
	}
	return ((void*)mem);
}
