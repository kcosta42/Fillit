/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:09 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/15 16:57:28 by kcosta           ###   ########.fr       */
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
}				t_tetriminos;

t_tetriminos	**get_tetriminos_list(const char *file);
int				check_tetriminos(t_tetriminos *tetriminos);

#endif
