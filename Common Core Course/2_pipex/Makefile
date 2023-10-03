# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 16:27:40 by aalkaisi          #+#    #+#              #
#    Updated: 2023/10/02 19:43:21 by aalkaisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS =	main_bonus.c ft_split_bonus.c extra_func_bonus.c extra_func2_bonus.c extra_func3_bonus.c\
		free_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c\

BONUS_OBJ = $(BONUS:.c=.o)

CC = cc

NAME = pipex

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
$(NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME)

clean:
	@rm -f $(BONUS_OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

bonus: fclean all

.PHONY: all clean fclean re bonus