CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Contact.cpp main.cpp PhoneBook.cpp
O_FILES = Contact.o main.o PhoneBook.o

NAME = PhoneBook

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME)

%.o: %.cpp PhoneBook.hpp Contact.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all