/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:12:19 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/10 18:52:16 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*ptrdst;

	ptrdst = dst;
	while (*src && len)
	{
		*(ptrdst++) = *(src++);
		len--;
	}
	while (len)
	{
		*(ptrdst++) = 0;
		len--;
	}
	return (dst);
}
