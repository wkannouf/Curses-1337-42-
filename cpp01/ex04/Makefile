CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp
O_FILE = main.o

NAME = replace

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
