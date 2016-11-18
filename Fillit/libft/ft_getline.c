/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:28 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/18 11:19:11 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		read_files(const int fd, char **file)
{
	int		read_ret;
	char	*buff;
	char	*tmp;

	buff = ft_strnew(BUFF_SIZE);
	read_ret = read(fd, buff, BUFF_SIZE);
	if (read_ret <= 0)
	{
		ft_strdel(&buff);
		return (read_ret);
	}
	*file = ft_strnew(0);
	while (read_ret > 0)
	{
		tmp = *file;
		*file = ft_strjoin(*file, buff);
		ft_strdel(&tmp);
		ft_strclr(buff);
		read_ret = read(fd, buff, BUFF_SIZE);
	}
	ft_strdel(&buff);
	return (1);
}

int		ft_getline(const int fd, char **line)
{
	static char		*file;
	char			*pfile;

	if (fd < 0 || !line)
		return (-1);
	if (read_files(fd, &file) == -1)
	{
		file = NULL;
		return (-1);
	}
	if (!file)
		return (0);
	if (!(ft_strcmp(file, "")))
		return (0);
	pfile = file;
	if ((pfile = ft_strchr(file, '\n')) == NULL)
		if ((pfile = ft_strchr(file, '\0')) == NULL)
			return (0);
	*line = ft_strsub(file, 0, pfile - file);
	file = pfile + 1;
	if (!pfile)
		file = NULL;
	return (1);
}
