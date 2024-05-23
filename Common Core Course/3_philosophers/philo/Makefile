# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:20:28 by aalkaisi          #+#    #+#              #
#    Updated: 2024/03/19 14:27:21 by aalkaisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c routine.c parse.c eating.c eating2.c\
		is_dead.c all_to_atoi.c atoi_with_check.c timer.c free.c\

OBJ = $(SRC:.c=.o)

CC = cc

NAME = philo

CFLAGS = -Wall -Werror -Wextra -pthread -g3

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