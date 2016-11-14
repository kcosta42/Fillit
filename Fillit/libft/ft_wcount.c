/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:00:16 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/04 13:24:13 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcount(const char *s, int c)
{
	int		wcount;

	wcount = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			wcount++;
		while (*s && !(*s == c))
			s++;
	}
	return (wcount);
}
