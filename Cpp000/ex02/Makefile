CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Account.cpp tests.cpp 
O_FILES = Account.o tests.o

NAME = Accounts

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME)

%.o: %.cpp Account.hpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all