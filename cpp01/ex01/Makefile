CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = Zombie.cpp ZombieHorde.cpp main.cpp
O_FILE = Zombie.o zombieHorde.o main.o

NAME = Moar_brainz

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
