/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:20:05 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 14:56:06 by kcosta           ###   ########.fr       */
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
	ft_putstr("origin: ");
	ft_putnbr(tetriminos->origin.x);
	ft_putchar(':');
	ft_putnbr(tetriminos->origin.y);
	ft_putchar('\n');
	ft_putchar(tetriminos->letter);
	ft_putchar('\n');
	ft_putstr("width: ");
	ft_putnbr(tetriminos->size.x);
	ft_putchar('\n');
	ft_putstr("height: ");
	ft_putnbr(tetriminos->size.y);
	ft_putchar('\n');
	ft_putchar('\n');
}

void	print_result(t_grid *grid)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < grid->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x < grid->prev_pos.x)
		{
			ft_putchar(grid->square[pos.y][pos.x]);
			pos.x++;
		}
		ft_putchar('\n');
		pos.y++;
	}
}

int		main(int argc, char **argv)
{
	t_tetriminos	**tetriminos;
	t_grid			*grid;
	int index;
	
	index = 0;
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
	solve(&grid, tetriminos);
	while (tetriminos[index])
	{
		print_content(tetriminos[index]);
		index++;
	}
	print_result(grid);
	return (1);
}
