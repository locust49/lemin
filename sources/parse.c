/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:57:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/08/02 07:05:53 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

string		ft_roomname(string line)
{
	// if (*line == '#')
	// {
	// 		free(line);
	// 	get_next_line(0, &line);
	// }
	if (*line == 'L')
		print_false('L');
	if (!ft_strchr(line, ' '))
		print_false(' ');
	return (ft_strsub(line, 0, (size_t)(ft_strchr(line, ' ') - line)));
}

void	get_ants(t_input **in, string line, int *row)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] && !ft_isdigit(line[i]))
			print_false('0');
	(*in)->ants = ft_atoi(line);
	(*in)->graph = (t_graph*)ft_memalloc(sizeof(t_graph));
	(*in)->graph->next = NULL;
	*row = 1;
}

// void	ft_strore_inout(t_input **in, string line, int *row)
// {
// 	if (!ft_strcmp(line, "##start"))
// 	{	
// 		get_next_line(0, &line);
// 		(*line == 'L') ? print_false('L') : 0;
// 		(*in)->start->vertex.id = -1;
// 		(*in)->start->vertex.name = ft_roomname(line);
// 		*row += 1;
// 	}
// 	if (!ft_strcmp(line, "##end"))
// 	{	
// 		get_next_line(0, &line);
// 		(*line == 'L') ? print_false('L') : 0;
// 		(*in)->.id = -2;
// 		(*in)->.name = ft_roomname(line);
// 		*row += 1;
// 	}
// 	//(*in)->next = 0;
// }

t_bool	ft_graph_is_empty(t_graph	*g)
{
	if (!g)
		return (true);
	return (false);
}

t_bool	ft_entrance_or_exit(string line)
{
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (true);
	return (false);
}

t_graph	*ft_create_vertex(string line, int id)
{
	t_graph *new;

	new = NULL;
	if ((new = (t_graph*)ft_memalloc(sizeof(t_graph))))
	{
		new->vertex.id = id;
		new->vertex.name = ft_roomname(line);
	}
	return (new);
}

void	ft_add_entrance_exit(t_graph *g, string line)
{
	t_graph	*new;
	int		id;

	id = (ft_strequ(line, "##start") ? -1 : -2);
	free(line);
	get_next_line(0, &line);
	new = ft_create_vertex(line, id);
	if (ft_graph_is_empty(g))
		g->next = NULL;
	else
		new->next = g;
	g = new;
	print_graph(g);
}


void	ft_add_to_graph(t_graph *graph, string line, int id)
{
	t_graph *new;
	t_graph	*last;

	new = ft_create_vertex(line, id);
	if (ft_graph_is_empty(graph))
	{
		graph = new;
		graph->next = NULL;
	}
	else
	{
		last = graph;
		while (last->next || last->vertex.id < 0)
			last = last->next;
		new->next = NULL;
		last->next = new;
	}
}

t_bool	ft_entrance_exit_added(t_graph *graph)
{
	if (graph && graph->vertex.id < 0)
		return (true);
	return (false);
}

t_bool	ft_valid_entrance_or_exit(t_graph *graph, string *line)
{
	if (ft_entrance_or_exit(graph))
	{
		free(line);
		get_next_line(0, &line);
		if (ft_valid_room(line))
			return (true);
		else
			return (ewewe);
		
	}
	return (false);
}
void	ft_store_rooms(t_input** in, string line)
{
	t_graph		*head;
	// t_graph		*tmp;
	static int	id;

	head = (*in)->graph;
	if (!ft_entrance_or_exit(line))
	{
		ft_add_to_graph((*in)->graph, line, id);
		// if (ft_graph_is_empty((*in)->graph))
		// {
		// 	(*in)->graph->vertex.id = id;
		// 	(*in)->graph->vertex.name = ft_roomname(line);
		// 	(*in)->graph->next = NULL;
		// }
		// else
		// {
		// 	tmp = (*in)->graph;
		// 	while (tmp->next)
		// 		tmp = tmp->next;
		// 	tmp->next = (t_graph*)ft_memalloc(sizeof(t_graph));
		// 	tmp->next->vertex.id = id;
		// 	tmp->next->vertex.name = ft_roomname(line);
		// 	tmp->next->next = NULL;
		// 	(*in)->graph = head;
		// }
		id += 1;
	}
	else
		ft_add_entrance_exit((*in)->graph, line);
}

void	get_input(t_input *in)
{
	string	line;
	int		row;
	int		gnl;

	row = 0;
	if (!(in = (t_input*)ft_memalloc(sizeof(t_input))))
		exit(-2);
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		row == 0 ? get_ants(&in, line, &row) : 0;
		(*line == 'L') ? print_false('L') : 0;
		//ft_strore_inout(&in, line, &row);
		if (*line == '#' && !ft_entrance_or_exit(line))
			continue ;
		if (ft_strchr(line, ' ') || ft_valid_entrance_or_exit(line))
			ft_store_rooms(&in, line);
		free(line);
	}
	print_list(in);
	ft_putchar('\n');
	//row != 3 ? print_false('I') : 0;
	gnl == -1 ? print_false('x') : 0;
	printf("Valid map");
}
