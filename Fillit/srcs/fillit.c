/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:20:05 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/14 21:08:29 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_content(t_list *elem)
{
	int				x;
	int				y;
	t_tetriminos	*tetriminos;

	x = 0;
	y = 0;
	tetriminos = (t_tetriminos*)elem->content;
	while (y < 4)
	{
		while (x < 4)
		{
			if (tetriminos->block[y][x])
				ft_putchar('#');
			else
				ft_putchar('.');
			x++;
		}
		ft_putchar('\n');
		y++;
		x = 0;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_list	*tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (-1);
	}
	if (!(tetriminos = get_tetriminos_list(argv[1])))
	{
		ft_putendl("error");
		return (-1);
	}
//	ft_lstiter(tetriminos, &print_content);
	return (1);
}
