/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:10:44 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/15 20:11:33 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_grid		*initialise_grid(t_grid *grid)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = -1;
	grid = (t_gridi*)ft_memalloc(sizeof(grid));
	grid->square = (char**)ft_memalloc(sizeof(char*) * 17);
	while(++pos.y < 4)
		grid->square[pos.y]= ft_strdup("................");
	grid->prev_pos.x = 16;
	grid->prev_pos.y = 16;
	grid->new_pos.x = 0;
	grid->new_pos.y = 0;
	return (grid);
}


