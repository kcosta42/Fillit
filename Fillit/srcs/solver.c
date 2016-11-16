/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:10:44 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 16:32:20 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

	pos.y = 0;
	while (pos.y <= (*grid)->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x <= (*grid)->prev_pos.x)
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
	while (pos.y <= (*grid)->prev_pos.y - (*tetriminos)->size.y)
	{
		pos.x = 0;
		while (pos.x <= (*grid)->prev_pos.x - (*tetriminos)->size.x)
		{
			if (put_tetriminos(grid, *tetriminos, pos))
			{
				if (solver(grid, tetriminos + 1))
					return (1);
				else
					remove_tetriminos(grid, *tetriminos);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void		reset_grid(t_grid **grid)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < (*grid)->prev_pos.y)
	{
		pos.x = 0;
		while (pos.x < (*grid)->prev_pos.x)
		{
			(*grid)->square[pos.y][pos.x] = '.';
			pos.x++;
		}
		pos.y++;
	}
}

void		solve(t_grid **grid, t_tetriminos **tetriminos)
{
	*grid = initialise_grid(*grid);
	while (!solver(grid, tetriminos))
	{
		(*grid)->prev_pos.x++;
		(*grid)->prev_pos.y++;
		reset_grid(grid);
	}
}
