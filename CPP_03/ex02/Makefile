NAME = ex02

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

OBJS := $(SRC:%.cpp=%.o)

CC = g++
FLAGS = -Wall -Wextra -Werror -I ./includes

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -std=c++98 $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re