/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:44:27 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/04 17:00:36 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte	*ptrdst;

	ptrdst = (t_byte*)dst;
	while (n--)
		*ptrdst++ = *(t_byte*)src++;
	return (dst);
}
