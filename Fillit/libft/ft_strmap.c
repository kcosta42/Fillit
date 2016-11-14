/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:05:16 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/05 20:25:53 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	char	*ptrmap;

	if (!s)
		return (NULL);
	if (!(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	ptrmap = map;
	while (*s)
		*(ptrmap++) = f(*(s++));
	*ptrmap = 0;
	return (map);
}
