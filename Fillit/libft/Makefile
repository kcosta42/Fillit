#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/02 10:00:00 by kcosta            #+#    #+#             *#
#*   Updated: 2016/11/14 17:10:34 by kcosta           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = ft_isalpha.o ft_lstadd.o ft_memalloc.o ft_memmove.o ft_putnbr.o \
		ft_strclr.o ft_striter.o ft_strmapi.o ft_strnstr.o ft_strtrim.o \
		ft_isascii.o ft_lstdel.o ft_memccpy.o ft_memset.o ft_putnbr_fd.o \
		ft_strcmp.o ft_striteri.o ft_strncat.o ft_strrchr.o ft_tolower.o \
		ft_atoi.o ft_isblank.o ft_lstdelone.o ft_memchr.o ft_putchar.o \
		ft_putstr.o ft_strcpy.o ft_strjoin.o ft_strncmp.o ft_strrev.o \
		ft_toupper.o ft_bzero.o ft_isdigit.o ft_lstiter.o ft_memcmp.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_strdel.o ft_strlcat.o ft_strncpy.o \
		ft_strsplit.o ft_wcount.o ft_dcount.o ft_isprint.o ft_lstmap.o \
		ft_memcpy.o ft_putendl.o ft_strcat.o ft_strdup.o ft_strlen.o \
		ft_strnequ.o ft_strstr.o ft_isalnum.o ft_itoa.o ft_lstnew.o \
		ft_memdel.o ft_putendl_fd.o ft_strchr.o ft_strequ.o ft_strmap.o \
		ft_strnew.o ft_strsub.o ft_isspace.o ft_islower.o ft_isupper.o \
		ft_lstaddback.o ft_getline.o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY: clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
