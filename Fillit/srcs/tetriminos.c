/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:51:38 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/14 17:28:52 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_list	*get_tetriminos_list(const char *file)
{
	t_list	*tetriminos;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	return (NULL);
}
