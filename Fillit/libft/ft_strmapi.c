/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:25:20 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/05 20:26:19 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	char	*ptrmap;
	int		index;

	if (!s)
		return (NULL);
	if (!(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	index = 0;
	ptrmap = map;
	while (*s)
		*(ptrmap++) = f(index++, *(s++));
	*ptrmap = 0;
	return (map);
}
