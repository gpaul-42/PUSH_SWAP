# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 03:32:26 by gpaul             #+#    #+#              #
#    Updated: 2021/11/27 18:03:27 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

_SRCS =		main.c				\
			cpy_arg.c			\
			cpy_arg2.c			\
			error.c				\
			operations.c		\
			push.c				\
			utils.c				\
			ft_is_sort.c		\
			solver.c			\
			sort.c				\
			radix.c				\


SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
SRCO = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror #-fsanitize=address #-g
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

.PHONY			:	all clean fclean re
