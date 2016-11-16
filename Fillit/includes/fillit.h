/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:09 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 14:02:07 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct	s_tetriminos
{
	int			block[4][4];
	t_vector	origin;
	t_vector	shape[4];
	t_vector	size;
	char		letter;
}				t_tetriminos;

typedef struct	s_grid
{
	char		**square;
	t_vector	prev_pos;
}				t_grid;

void			solve(t_grid **grid, t_tetriminos **tetriminos);
t_tetriminos	**get_tetriminos_list(const char *file);
int				check_tetriminos(t_tetriminos *tetriminos);

#endif
