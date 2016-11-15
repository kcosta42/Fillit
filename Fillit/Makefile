#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/14 16:52:56 by kcosta            #+#    #+#             *#
#*   Updated: 2016/11/15 13:10:48 by kcosta           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
MAKE = make -C
LIBFT = libft/
INCLUDESPATH = includes/
SRCSPATH = srcs/
SRCS = fillit.c tetriminos.c check.c
OBJS = $(SRCS:%.c=%.o)

%.o: $(SRCSPATH)%.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) $(LIBFT) fclean && $(MAKE) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(LIBFT)$(INCLUDESPATH) -L $(LIBFT) -lft

.PHONY : clean

clean:
	$(MAKE) $(LIBFT) clean
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT) fclean
	/bin/rm -f $(NAME)

re: fclean all
