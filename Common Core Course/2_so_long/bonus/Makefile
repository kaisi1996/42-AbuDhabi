# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 18:09:43 by aalkaisi          #+#    #+#              #
#    Updated: 2023/09/06 17:23:53 by aalkaisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS = main_bonus.c player_animation_bonus.c zombie_bonus.c move_bonus.c\
		ft_itoa_bonus.c map_copy_bonus.c building_map_bonus.c parsing1_bonus.c\
		parsing2_bonus.c put_zombie_bonus.c others_bonus.c free_bonus.c\
		get_next_line_bonus.c get_next_line_utils_bonus.c\

BONUS_OBJ = $(BONUS:.c=.o)

CC = cc

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -Imlx $^ -o $@
	
$(NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	@rm -f $(BONUS_OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

bonus: fclean all

.PHONY: all clean fclean re bonus