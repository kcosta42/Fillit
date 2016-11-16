/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:20:05 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 16:31:49 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_grid	*initialise_grid(t_grid *grid)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = -1;
	grid = (t_grid*)ft_memalloc(sizeof(grid));
	grid->square = (char**)ft_memalloc(sizeof(char*) * 17);
	while (++pos.y < 16)
		grid->square[pos.y] = ft_strdup("................");
	grid->prev_pos.x = 2;
	grid->prev_pos.y = 2;
	return (grid);
}

void	print_result(t_grid *grid)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y <= grid->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x <= grid->prev_pos.x)
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
	print_result(grid);
	return (1);
}
