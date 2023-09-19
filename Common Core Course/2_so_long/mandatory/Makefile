# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 18:09:43 by aalkaisi          #+#    #+#              #
#    Updated: 2023/09/06 17:48:39 by aalkaisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c move.c ft_itoa.c map_copy.c building_map.c parsing1.c\
		parsing2.c others.c free.c get_next_line.c get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

CC = cc

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -Imlx $^ -o $@
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re