/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:50:41 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/01 21:12:36 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_parent *new_parent(t_room *room)
{
	t_parent	*new;

	if (!(new = (t_parent*)malloc(sizeof(t_parent))))
		exit(-1);
	new->room = room;
	new->next = NULL;
	return (new);
}

void    add_parents(t_htparent **parents, t_room *toadd)
{
	if ( !(*parents))
	{
		if (!(*parents = (t_htparent*)malloc(sizeof(t_htparent))))
			exit(-1);
		(*parents)->head = new_parent(toadd);
		(*parents)->tail = (*parents)->head;
		return ;
	}
	(*parents)->tail->next = new_parent(toadd);
	(*parents)->tail = (*parents)->tail->next;
}