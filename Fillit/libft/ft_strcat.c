/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:20:16 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/04 13:18:20 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptrs1;

	ptrs1 = s1;
	while (*ptrs1)
		ptrs1++;
	ptrs1 = ft_strcpy(ptrs1, s2);
	return (s1);
}
