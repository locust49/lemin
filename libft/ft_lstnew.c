/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:21:41 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 15:06:38 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		new->content = malloc(content_size);
		if (!(new->content))
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
