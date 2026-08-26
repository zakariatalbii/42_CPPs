SRCS = main.cpp Contact.cpp PhoneBook.cpp utils.cpp

OBJS= $(SRCS:.cpp=.o)

NAME = phonebook

CC = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

%.o: %.cpp Contact.hpp PhoneBook.hpp utils.hpp
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all