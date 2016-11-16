/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:25:10 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 18:21:20 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				check_block(t_tetriminos *tetriminos)
{
	t_vector	pos;
	t_vector	connected;

	pos.x = -1;
	connected.y = 0;
	while (++pos.x < 4)
	{
		pos.y = -1;
		connected.x = 0;
		while (++pos.y < 4)
			if ((tetriminos->shape[pos.x].x + 1 == tetriminos->shape[pos.y].x &&
				tetriminos->shape[pos.x].y == tetriminos->shape[pos.y].y) ||
				(tetriminos->shape[pos.x].x - 1 == tetriminos->shape[pos.y].x &&
				tetriminos->shape[pos.x].y == tetriminos->shape[pos.y].y) ||
				(tetriminos->shape[pos.x].x == tetriminos->shape[pos.y].x &&
				tetriminos->shape[pos.x].y + 1 == tetriminos->shape[pos.y].y) ||
				(tetriminos->shape[pos.x].x == tetriminos->shape[pos.y].x &&
				tetriminos->shape[pos.x].y - 1 == tetriminos->shape[pos.y].y))
				connected.x++;
		connected.y = (connected.x > 1) ? 1 : connected.y;
		if (!connected.x)
			return (0);
	}
	return (connected.y);
}

int				check_tetriminos(t_tetriminos *tetriminos)
{
	int			block;
	t_vector	pos;
	int			index;

	block = 0;
	pos.x = -1;
	pos.y = -1;
	index = 0;
	while (++pos.y < 4)
	{
		while (++pos.x < 4)
		{
			if (tetriminos->block[pos.y][pos.x])
			{
				tetriminos->shape[index++] = pos;
				block++;
			}
			if (index > 4)
				return (0);
		}
		pos.x = -1;
	}
	if (block != 4)
		return (0);
	return (check_block(tetriminos));
}
