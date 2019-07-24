/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 01:22:55 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 14:46:30 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t sizel;

	sizel = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		sizel++;
		lst = lst->next;
	}
	return (sizel);
}
