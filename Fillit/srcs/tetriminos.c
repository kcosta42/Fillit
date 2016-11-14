/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:51:38 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/14 21:09:17 by kcosta           ###   ########.fr       */
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
	//void	print_content(*t_tetriminos);
	//print_content(tetriminos);
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

t_list				*get_tetriminos_list(const char *file)
{
	int				fd;
	char			*sample;
	int				ret_val;
	t_list			*tetriminos;
	t_tetriminos	*tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if ((ret_val = get_sample(fd, &sample)) < 1)
		return (NULL);
	if (!(tetriminos = ft_lstnew(new_tetriminos(sample), sizeof(t_tetriminos))))
		return (NULL);
	ft_getline(fd, &sample);
	while ((ret_val = get_sample(fd, &sample)))
	{
		if (ret_val == -1)
			return (NULL);
		if (!(tmp = new_tetriminos(sample)))
			return (NULL);
		ft_lstaddback(&tetriminos, ft_lstnew(tmp, sizeof(t_tetriminos)));
		ft_getline(fd, &sample);
	}
	void print_content(t_list *elem);
	print_content(tetriminos);
	if (close(fd) == -1)
		return (NULL);
	return (tetriminos);
}
