SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS= $(SRCS:.cpp=.o)

NAME = scavTrap

CC = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all