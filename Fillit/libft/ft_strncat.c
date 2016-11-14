/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:20:25 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/06 15:08:19 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptrs1;

	ptrs1 = s1;
	while (*ptrs1)
		ptrs1++;
	while (n-- && *s2)
		*(ptrs1++) = *(s2++);
	*ptrs1 = 0;
	return (s1);
}
