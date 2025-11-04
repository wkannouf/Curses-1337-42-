CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp Harl.cpp
O_FILE = main.o Harl.o

NAME = Harl

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp Harl.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
