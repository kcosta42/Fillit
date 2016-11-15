/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:25:10 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/15 14:54:35 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_block(t_tetriminos *tetriminos)
{
	int			i;
	int			j;
	int			connected;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		connected = 0;
		while (!connected && ++j < 4)
		{
			if ((tetriminos->shape[i].x + 1 == tetriminos->shape[j].x &&
				tetriminos->shape[i].y == tetriminos->shape[j].y) ||
				(tetriminos->shape[i].x - 1 == tetriminos->shape[j].x &&
				tetriminos->shape[i].y == tetriminos->shape[j].y) ||
				(tetriminos->shape[i].x == tetriminos->shape[j].x &&
				tetriminos->shape[i].y + 1 == tetriminos->shape[j].y) ||
				(tetriminos->shape[i].x == tetriminos->shape[j].x &&
				tetriminos->shape[i].y - 1 == tetriminos->shape[j].y))
				connected = 1;
		}
		if (!connected)
			return (0);
	}
	return (1);
}

int		check_tetriminos(t_tetriminos *tetriminos)
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
