CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
O_FILE = main.o Animal.o Cat.o Dog.o WrongAnimal.o WrongCat.o
NAME = Animal

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
