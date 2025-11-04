CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp HumanB.cpp HumanA.cpp  Weapon.cpp
O_FILE = main.o HumanB.o HumanA.o Weapon.o

NAME = Unnecessary_violence

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
