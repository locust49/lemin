/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_elt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:52:42 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:19:50 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_elt(t_list *lst, t_list *new, int index)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	i = 0;
	head = lst;
	tmp = lst->next;
	if (index == 0)
	{
		ft_lstadd(&lst, new);
		return (lst);
	}
	while (i < index - 1)
	{
		lst = lst->next;
		tmp = tmp->next;
		i++;
	}
	new->next = tmp;
	lst->next = new;
	return (head);
}
