CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
O_FILE = main.o ClapTrap.o ScavTrap.o FragTrap.o DiamondTrap.o
NAME = DiamondTrap

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all