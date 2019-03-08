# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 10:00:00 by kcosta            #+#    #+#              #
#    Updated: 2019/03/08 15:13:53 by kcosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========== Colors =========== #
CLEAR		:= "\033[2K"
UP			:= "\033[A"
EOC			:= "\033[0;0m"
BLACK		:= "\033[0;30m"
RED			:= "\033[0;31m"
GREEN		:= "\033[0;32m"
YELLOW	:= "\033[0;33m"
BLUE		:= "\033[0;34m"
PURPLE	:= "\033[0;35m"
CYAN		:= "\033[0;36m"
WHITE		:= "\033[0;37m"
# ============================== #

# ========== Editable ========== #
NAME		:= fillit
# ============================== #

# ========== Standard ========== #
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror
# ============================== #

# =========== Files ============ #
SRCS_FILES		:=	fillit.c			\
									tetriminos.c	\
									check.c				\
									solver.c
HEADERS_FILES	:=	fillit.h
# ============================== #

# ========== Sources =========== #
SRCS_PATH	:= srcs/
SRCS			:= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
# ============================== #

# ========== Objects =========== #
OBJS_PATH	:= objs/
OBJS			:= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))
# ============================== #

# ========== Includes ========== #
INCLUDES_PATH	:= includes/
INCLUDES			:= -I $(INCLUDES_PATH)
HEADERS				:= $(addprefix $(INCLUDES_PATH), $(HEADERS_FILES))
# ============================== #

# ========== Libraries ========= #
LIBFT_PATH			:= libft/
LIBFT_INCLUDES	:= -I libft/includes
LIBFT						:= -L $(LIBFT_PATH) -lft
# ============================== #

.PHONY: all libft submodule clean fclean re

all: submodule libft $(NAME)

submodule:
	git submodule init
	git submodule update --remote

libft:
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS) $(LIBFT_PATH)/libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -fv $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -fv $(NAME)

re: fclean all
