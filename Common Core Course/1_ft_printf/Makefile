# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 16:50:11 by aalkaisi          #+#    #+#              #
#    Updated: 2023/03/11 13:30:52 by aalkaisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned.c ft_puthexad.c ft_putaddress.c\

OBJ = $(SRC:.c=.o)

CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	
clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

bonus: $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re