SRCS = main.cpp Zombie.cpp zombieHorde.cpp

OBJS= $(SRCS:.cpp=.o)

NAME = brainz

CC = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

%.o: %.cpp Zombie.hpp
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all