/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:41:48 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/05 20:28:30 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		words;
	int		index;
	int		length;

	if (!s)
		return (NULL);
	index = 0;
	words = ft_wcount(s, c) + 1;
	if (!(split = (char**)malloc(sizeof(char*) * words)))
		return (NULL);
	while (index < words - 1)
	{
		length = 0;
		while (*s && *s == c)
			s++;
		while (s[length] && !(s[length] == c))
			length++;
		split[index] = ft_strsub(s, 0, length);
		index++;
		s += length;
	}
	split[index] = 0;
	return (split);
}
