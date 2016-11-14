/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:47:06 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/05 20:07:04 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(dup, s1));
}
