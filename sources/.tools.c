/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otel-jac <otel-jac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:47:33 by slyazid           #+#    #+#             */
/*   Updated: 2019/10/26 17:51:50 by otel-jac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	print_path(t_path *path)
{
	t_path *tmp;
	int i = 0;

	tmp = path;
	while (tmp)
	{
		i++;
		printf("    path: %d\n", i);
		printf("	");
		print_parents(tmp->paths);
		printf("\n");
		tmp = tmp->next;
	}
}

void	print_plist(t_data *data)
{
	int i = -1;
	t_room *tmp;

	while (++i < MAX_NODE)
	{
		if (data->r_tab[i])
		{
			tmp = data->r_tab[i]->head;
			while (tmp)
			{
				if (tmp->parent)
					printf("parent of node %s is %s\n", tmp->name, tmp->parent->name);
				tmp = tmp->next;
			}
		}
	}
}

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
		printf("(%s,%d)<-> ", tmp->to->name, tmp->flow);
		tmp = tmp->next;
	}
}

void	print_queue(t_queue *queue)
{
	while (queue)
	{
		printf("(%d,[%s]) -->", queue->rooms->capacity, queue->rooms->name);
		queue = queue->next;
	}
	printf("\n");
}

void	print_parents(t_htparent *parents)
{
	t_parent *p;

	p = parents->head;
	while (p)
	{
		printf("\x1b[33:0m%s\x1b[0:0m ", p->room->name);
		p = p->next;
	}
}

void	print_groups(t_group *group)
{
	t_group *tmp;
	int i  = 0;

	tmp = group;
	while (tmp)
	{
		i++;
		printf("group %d\n", i);
		printf("num of path: %d\n", tmp->path_num);
		printf("num of node: %d\n", tmp->node_num);
		printf("group score: %d\n", tmp->group_score);
		print_path(tmp->path->head);
		tmp = tmp->next;
	}
}

void	print__best_groups(t_group *group)
{
	printf("best group\n");
	printf("num of path: %d\n", group->path_num);
	printf("num of node: %d\n", group->node_num);
	printf("group score: %d\n", group->group_score);
	print_path(group->path->head);
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
