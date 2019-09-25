/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:47:33 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/19 18:37:31 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	print_rooms(t_data *data, int link)
{
	int		i = -1;
	t_room	*tmp;
	t_link	*lnk;
	
	while (++i < MAX_NODE)
	{
		if (data->r_tab[i]->head && !data->r_tab[i]->head->next)
		{
			printf("\nonly one = %s ", data->r_tab[i]->head->name);
			if (link)
			{
				lnk = data->r_tab[i]->head->links;
				// printf("{%s}\n", data->r_tab[i]->head->links->to->name);
				while (lnk)
				{
					printf(" |%s| ", lnk->to->name);
					lnk = lnk->next;
				}
				// ft_putchar('\n');
			}
		}
		else if (data->r_tab[i]->head && data->r_tab[i]->head->next)
		{
			printf("\nmany ones\n");
			printf("*) %s  ", data->r_tab[i]->head->name);
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
		// ft_putchar('*');
	}
}

void	print_ices(t_ind *ices)
{

	printf("________________\n");
	printf("head	:	%s  	|\n", ices->head->name);
	printf("tail	:	%s	|\n", ices->tail->name);
	printf("END	:	%s  	|\n", ices->end->name);
	printf("START	:	%s  	|\n", ices->start->name);
	printf("________________\n");
}
