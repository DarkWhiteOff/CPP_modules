NAME = sed

SRC = main.cpp

OBJS := $(SRC:%.cpp=%.o)

CC = c++
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
	rm -rf file.replace

re: fclean all

.PHONY: all clean fclean re