/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:32:26 by slyazid           #+#    #+#             */
/*   Updated: 2019/09/30 18:12:28 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			convert_letter(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 35);
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (c);
}

long long	get_hash_id(t_string s)
{
	const int		p = 67;
	const long long	m = MAX_NODE;
	int				c;
	int				hash_value;
	long long		p_pow;

	hash_value = 0;
	p_pow = 1;
	while (*s)
	{
		c = convert_letter(*s) + 1;
		hash_value = (hash_value % m + (c % m * p_pow % m) % m) % m;
		p_pow = (p_pow % m * p % m) % m;
		s++;
	}
	return (hash_value);
}
