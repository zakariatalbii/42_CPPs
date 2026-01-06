SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS= $(SRCS:.cpp=.o)

NAME = violence

CC = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

%.o: %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all