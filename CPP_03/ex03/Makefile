NAME = ex03

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp

OBJS = $(SRC:%.cpp=%.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow -I ./includes

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re