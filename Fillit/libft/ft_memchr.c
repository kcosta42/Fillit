/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:09:46 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/04 13:53:01 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*ptrs;

	ptrs = (t_byte*)s;
	while (n > 0)
	{
		if (*ptrs == (t_byte)c)
			return (ptrs);
		ptrs++;
		n--;
	}
	return (NULL);
}
