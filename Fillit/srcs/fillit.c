/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:20:05 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/14 17:33:09 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	t_list	*tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file\n");
		return (-1);
	}
	tetriminos = get_tetriminos_list(argv[1]);
	tetriminos = NULL;
	return (1);
}
