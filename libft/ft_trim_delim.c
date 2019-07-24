/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 00:53:29 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/23 00:54:14 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_delim(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*trim;

	i = 0;
	k = 0;
	trim = NULL;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] == c)
		i++;
	if (!s[i])
		return ("");
	while (s[j - 1] == c)
		j--;
	trim = (char*)malloc((j - i + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (i < j)
		trim[k++] = s[i++];
	trim[k] = '\0';
	return (trim);
}
