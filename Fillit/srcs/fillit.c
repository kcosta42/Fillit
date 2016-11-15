/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:20:05 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/15 16:36:18 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_content(t_tetriminos *tetriminos)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (tetriminos->block[y][x])
				ft_putchar('#');
			else
				ft_putchar('.');
			x++;
		}
		ft_putchar('\n');
		y++;
		x = 0;
	}
	x = 0;
	while (x < 4)
	{
		ft_putnbr(tetriminos->shape[x].x);
		ft_putchar(':');
		ft_putnbr(tetriminos->shape[x].y);
		ft_putchar('\n');
		x++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_tetriminos	**tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (-1);
	}
	if (!(tetriminos = get_tetriminos_list(argv[1])))
	{
		ft_putendl("error");
		return (-1);
	}
	int index;
	index = 0;
	while (tetriminos[index])
	{
		print_content(tetriminos[index]);
		index++;
	}
	return (1);
}
