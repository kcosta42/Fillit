/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:31:35 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/05 20:51:07 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*ptrstr;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ptrstr = str;
	while (size + 1)
	{
		*ptrstr = 0;
		ptrstr++;
		size--;
	}
	return (str);
}
