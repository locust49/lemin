/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:27:54 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:21:51 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putlst(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			ft_putstr((char const *)lst->content);
			ft_putstr(" | ");
			ft_putnbr(lst->content_size);
			if (lst->next)
				ft_putstr(" -> ");
			lst = lst->next;
		}
	}
}
