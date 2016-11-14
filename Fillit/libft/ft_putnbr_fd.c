/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:13:53 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/06 12:16:01 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		digits;
	int		power;

	digits = ft_dcount(n);
	power = 1;
	while (--digits > 0)
		power *= 10;
	nbr = (long)n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	while (power > 0)
	{
		ft_putchar_fd(nbr / power + '0', fd);
		nbr %= power;
		power /= 10;
	}
}
