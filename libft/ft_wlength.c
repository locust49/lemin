/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlength.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:02:04 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/25 22:10:32 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wlength(const char *str, char c)
{
	size_t sizew;

	sizew = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		sizew++;
		str++;
	}
	return (sizew);
}
