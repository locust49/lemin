/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 11:51:11 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/24 23:13:06 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
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
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return (ft_strdup(""));
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	trim = (char*)malloc((j - i + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (i < j)
		trim[k++] = s[i++];
	trim[k] = '\0';
	return (trim);
}
