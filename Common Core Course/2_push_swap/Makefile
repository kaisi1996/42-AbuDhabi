# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 15:36:47 by aalkaisi          #+#    #+#              #
#    Updated: 2023/08/12 20:24:57 by aalkaisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	push_swap.c parsing.c extra_func.c ft_atoi_ch.c ft_split.c index_pnl.c movments.c sort_3.c\
		sort_large.c sort_small.c stacks.c\

OBJ = $(SRC:.c=.o)

CC = cc

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
