CXX = c++

NAME = Zombie

SRC = main.cpp Zombie.cpp zombieHorde.cpp

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re