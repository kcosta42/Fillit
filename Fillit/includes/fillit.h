/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:09 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/15 08:57:06 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_tetriminos
{
	int			block[4][4];
}				t_tetriminos;

t_tetriminos	**get_tetriminos_list(const char *file);
t_tetriminos	*new_tetriminos(const char *sample);

#endif
