CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
O_FILE = main.o AMateria.o Character.o Cure.o Ice.o MateriaSource.o
NAME = Materia

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

%.o: %.cpp AMateria.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp Cure.hpp Ice.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all