# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 03:32:26 by gpaul             #+#    #+#              #
#    Updated: 2021/09/14 18:08:44 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

_SRCS =		main.c			\
			cpy_arg.c		\
			error.c			\
			operations.c	\
			push.c			\
			utils.c			\

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
SRCO = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror #-g -fsanitize=address
INC = -I include/

all : $(NAME)

$(NAME) : $(SRCO)
	make -C libft
	gcc -o $(NAME) -Llibft -lft $(SRCO)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	rm -f $(SRCO)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft

re :
	make fclean
	make
