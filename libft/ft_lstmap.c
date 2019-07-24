/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:37:39 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/25 21:06:09 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	if (!new)
		return (NULL);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
			return (NULL);
		new = new->next;
	}
	new->next = NULL;
	return (first);
}
