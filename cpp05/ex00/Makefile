CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Bureaucrat.cpp main.cpp
O_FILES = Bureaucrat.o main.o

NAME = Bureaucrat 

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean
