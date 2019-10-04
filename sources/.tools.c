/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:47:33 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/03 21:55:54 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	print_parent(t_ind *ices)
{
	t_room *room;

	room = ices->end;
	while (room != ices->start)
	{
		printf(" %s <-", room->name);
		if (room->parents)
			print_parents(room->parents);
		else
		{
			printf("No room->parents\n");
		}
		
		room = room->parent;
		if (room == ices->start)
		{	
			printf(" %s ", room->name);
		}
	}
}

void	print_short(t_ind *ices)
{
	t_room	*room;
	t_link	*link;

	room = ices->start;
	while (room != ices->end)
	{
		printf("%s -> ", room->name);
		link = room->links;
		while (link)
		{
			if (link->flow == 0)
			{
				room = link->to;
				break ;
			}
			link = link->next;
		}
		room = link->to;
		if (room == ices->end)
		{
			printf("%s", room->name);
			break;
		}
	}
}

void	print_rooms(t_data *data, int link)
{
	int		i = -1;
	t_room	*tmp;
	t_link	*lnk;
	
	while (++i < MAX_NODE)
	{
		if (data->r_tab[i]->head && !data->r_tab[i]->head->next)
		{
			printf("\nonly one = %5s -- ", data->r_tab[i]->head->name);
			if (link)
			{
				lnk = data->r_tab[i]->head->links;
				// printf("{%s}\n", data->r_tab[i]->head->links->to->name);
				while (lnk)
				{
					printf("|%5s: %d| ", lnk->to->name, lnk->to->visited);
					lnk = lnk->next;
				}
			}
			ft_putchar('\n');
		}
		else if (data->r_tab[i]->head && data->r_tab[i]->head->next)
		{
			printf("\nmany ones\n");
			printf("\x1b[33:0m*)\x1b[0:0m %s  ", data->r_tab[i]->head->name);
			if (link)
			{
				lnk = data->r_tab[i]->head->links;
				while (lnk)
				{
					printf(" | %s", lnk->to->name);
					lnk = lnk->next;
				}
			}
			// ft_putchar('\n');
			tmp = data->r_tab[i]->head->next;
			while (tmp)
			{
				printf("\n-> %s", tmp->name);
				if (link)
				{
					lnk = tmp->links;
					while (lnk)
					{
						printf(" |%s| ", lnk->to->name);
						lnk = lnk->next;
					}
				}
				ft_putchar('\n');
				tmp = tmp->next;
			}
			printf("\n------\n");
		}
		else
			continue ;
	}
	ft_putchar('\n');
}

void	print_links(t_link *lnk)
{
	t_link *tmp;

	tmp = lnk;
	printf("links:\n\x1b[34:0m(x)\x1b[0:0m ");
	while (tmp)
	{
		printf("(%s,%d)<-> ", tmp->to->name, tmp->to->visited);
		tmp = tmp->next;
	}
	printf("(null)\n");
}

void	print_queue(t_queue *queue)
{
	printf("\n\x1b[33:0m*)\x1b[0:0m");
	while (queue)
	{
		printf(" (%d,[%s]) -->", queue->rooms->capacity, queue->rooms->name);
		queue = queue->next;
	}
	printf(" (null)");
	printf("\n\n");
}

void	print_parents(t_htparent *parents)
{
	t_parent *p;

	p = parents->head;
	while (p)
	{
		printf("\x1b[33:0m %s \x1b[0:0m + ", p->room->name);
		p = p->next;
	}
	printf(" (null)\n");
}

void	print_ices(t_ind *ices)
{

	printf("________________\n");
	// printf("head	:	%s  	|\n", ices->head->name);
	// printf("tail	:	%s	|\n", ices->tail->name);
	printf("END	:	%s  	|\n", ices->end->name);
	printf("START	:	%s  	|\n", ices->start->name);
	printf("________________\n");
}
