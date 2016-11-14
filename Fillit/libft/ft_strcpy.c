/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:39:38 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/04 13:56:51 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptrdst;

	ptrdst = dst;
	while (*src)
		*(ptrdst++) = *(src++);
	*ptrdst = *src;
	return (dst);
}
