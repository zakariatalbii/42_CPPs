SRCS = main.cpp Fixed.cpp

OBJS= $(SRCS:.cpp=.o)

NAME = fixed

CC = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

%.o: %.cpp Fixed.hpp
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all