/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:05:51 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/07 00:28:39 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				i;
	char			*str;

	if (!(str = ft_strnew(ft_dcount(n) + (n < 0))))
		return (NULL);
	sign = n;
	nbr = (sign < 0) ? -n : n;
	i = 0;
	if (!nbr)
		str[i++] = '0';
	while (nbr > 0)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = 0;
	str = ft_strrev(str);
	return (str);
}
