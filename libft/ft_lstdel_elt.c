/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_elt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 00:26:02 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:20:08 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstdel_head(t_list *lst)
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = lst->next;
	free(lst);
	return (new);
}

static t_list	*ft_lstdel_end(t_list *lst)
{
	t_list *tmp;
	t_list *head;

	if (!lst)
		return (NULL);
	head = lst;
	tmp = lst->next;
	if (!tmp)
	{
		free(lst);
		return (lst);
	}
	while (tmp)
	{
		if (!tmp)
		{
			lst->next = NULL;
			free(tmp);
		}
		tmp = tmp->next;
	}
	free(tmp);
	return (head);
}

t_list			*ft_lstdel_elt(t_list *lst, int index)
{
	int		i;
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return (NULL);
	i = 0;
	head = lst;
	tmp = lst->next;
	if (index == 0)
		return (ft_lstdel_head(lst));
	while (i < index - 1)
	{
		if (!tmp)
			return (ft_lstdel_end(lst));
		lst = lst->next;
		tmp = tmp->next;
		i++;
	}
	lst->next = tmp->next;
	free(tmp);
	return (head);
}
