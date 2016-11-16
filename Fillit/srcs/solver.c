/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:10:44 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 15:00:33 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_grid		*initialise_grid(t_grid *grid)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = -1;
	grid = (t_grid*)ft_memalloc(sizeof(grid));
	grid->square = (char**)ft_memalloc(sizeof(char*) * 17);
	while (++pos.y < 16)
		grid->square[pos.y] = ft_strdup("................");
	grid->prev_pos.x = 16;
	grid->prev_pos.y = 16;
	return (grid);
}

int			put_tetriminos(t_grid **grid, t_tetriminos *tetriminos,
							t_vector pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (!((*grid)->square[tetriminos->shape[i].y
							- tetriminos->origin.y + pos.y]
							[tetriminos->shape[i].x
							- tetriminos->origin.x + pos.x] == '.'))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*grid)->square[tetriminos->shape[i].y
						- tetriminos->origin.y + pos.y]
						[tetriminos->shape[i].x
						- tetriminos->origin.x + pos.x] = tetriminos->letter;
		i++;
	}
	return (1);
}

int			remove_tetriminos(t_grid **grid, t_tetriminos *tetriminos)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < (*grid)->prev_pos.y)
	{
		while (pos.x < (*grid)->prev_pos.x)
		{
			if ((*grid)->square[pos.y][pos.x] == tetriminos->letter)
				(*grid)->square[pos.y][pos.x] = '.';
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

int			solver(t_grid **grid, t_tetriminos **tetriminos)
{
	t_vector	pos;

	pos.y = 0;
	if (!*tetriminos)
		return (1);
	while (pos.y < (*grid)->prev_pos.y - (*tetriminos)->size.y + 1)
	{
		pos.x = 0;
		while (pos.x < (*grid)->prev_pos.x - (*tetriminos)->size.x + 1)
		{
			if (put_tetriminos(grid, *tetriminos, pos))
			{
				if (solver(grid, tetriminos + 1))
				{
					return (1);
				}
				else
					remove_tetriminos(grid, *tetriminos);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void		solve(t_grid **grid, t_tetriminos **tetriminos)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = -1;
	*grid = initialise_grid(*grid);
	solver(grid, tetriminos);
}
