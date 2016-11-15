/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:51:38 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/15 09:00:44 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

t_tetriminos		*create_tetriminos(void)
{
	int				x;
	int				y;
	t_tetriminos	*tetriminos;

	x = 0;
	y = 0;
	if (!(tetriminos = (t_tetriminos*)ft_memalloc(sizeof(t_tetriminos))))
		return (NULL);
	while (y < 4)
	{
		while (x < 4)
		{
			tetriminos->block[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (tetriminos);
}

t_tetriminos		*new_tetriminos(const char *sample)
{
	int				x;
	int				y;
	t_tetriminos	*tetriminos;

	x = 0;
	y = 0;
	if (!(tetriminos = create_tetriminos()))
		return (NULL);
	while (y < 4)
	{
		while (x < 4)
		{
			if (*sample != '.' && *sample != '#')
				return (NULL);
			if (*(sample++) == '#')
				tetriminos->block[y][x] = 1;
			x++;
		}
		if (*(sample++) != '\n')
			return (NULL);
		x = 0;
		y++;
	}
	return (tetriminos);
}

int					get_sample(int fd, char **sample)
{
	char			*buff;
	int				i;

	i = 0;
	*sample = ft_strnew(5 * 4);
	while (i++ < 4)
	{
		if (ft_getline(fd, &buff) > 0)
		{
			buff = ft_strjoin(buff, "\n");
			if (ft_strlen(buff) == 5)
				ft_strcat(*sample, buff);
			else
				return (-1);
		}
		else
			return (0);
	}
	return (1);
}

t_tetriminos		**get_tetriminos_list(const char *file)
{
	int				fd;
	char			*sample;
	int				ret_val;
	t_tetriminos	**tetriminos;
	int				index;

	index = 0;
	ret_val = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	tetriminos = (t_tetriminos**)ft_memalloc(sizeof(t_tetriminos*) * 26);
	while ((ret_val = get_sample(fd, &sample)))
	{
		if (ret_val == -1)
			return (NULL);
		if (!(tetriminos[index] = new_tetriminos(sample)))
			return (NULL);
		ft_getline(fd, &sample);
		index++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (tetriminos);
}
