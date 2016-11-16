/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:51:38 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/16 15:58:47 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetriminos		*create_tetriminos(void)
{
	static int		index = 0;
	t_vector		pos;
	t_tetriminos	*tetriminos;

	pos.y = -1;
	if (!(tetriminos = (t_tetriminos*)ft_memalloc(sizeof(t_tetriminos))))
		return (NULL);
	while (++pos.y < 4)
	{
		pos.x = -1;
		while (++pos.x < 4)
			tetriminos->block[pos.y][pos.x] = 0;
	}
	tetriminos->letter = 'A' + index++;
	return (tetriminos);
}

t_tetriminos		*get_origin(t_tetriminos *tetriminos)
{
	t_vector	min;
	t_vector	max;
	int			index;

	min.x = 5;
	min.y = 5;
	max.x = 0;
	max.y = 0;
	index = 0;
	while (index < 4)
	{
		if (tetriminos->shape[index].x < min.x)
			min.x = tetriminos->shape[index].x;
		if (tetriminos->shape[index].y < min.y)
			min.y = tetriminos->shape[index].y;
		if (tetriminos->shape[index].x > max.x)
			max.x = tetriminos->shape[index].x;
		if (tetriminos->shape[index].y > max.y)
			max.y = tetriminos->shape[index].y;
		index++;
	}
	tetriminos->origin = min;
	tetriminos->size.x = max.x - min.x;
	tetriminos->size.y = max.y - min.y;
	return (tetriminos);
}

t_tetriminos		*new_tetriminos(const char *sample)
{
	t_vector		pos;
	t_tetriminos	*tetriminos;

	pos.y = -1;
	if (!(tetriminos = create_tetriminos()))
		return (NULL);
	while (++pos.y < 4)
	{
		pos.x = -1;
		while (++pos.x < 4)
		{
			if (*sample != '.' && *sample != '#')
				return (NULL);
			if (*(sample++) == '#')
				tetriminos->block[pos.y][pos.x] = 1;
		}
		if (*(sample++) != '\n')
			return (NULL);
	}
	if (!(check_tetriminos(tetriminos)))
		return (NULL);
	tetriminos = get_origin(tetriminos);
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
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	tetriminos = (t_tetriminos**)ft_memalloc(sizeof(t_tetriminos*) * 27);
	while ((ret_val = get_sample(fd, &sample)))
	{
		if (ret_val == -1)
			return (NULL);
		if (!(tetriminos[index] = new_tetriminos(sample)))
			return (NULL);
		ret_val = ft_getline(fd, &sample);
		if (ret_val && *sample)
			return (NULL);
		index++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (tetriminos);
}
