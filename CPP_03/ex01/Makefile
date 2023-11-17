SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp

INCLUDE = ClapTrap.hpp ScavTrap.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = ClapTrap
COMP = c++

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME): $(OBJS)
			${COMP} $(FLAGS) -o $(NAME) $(OBJS) 

%.o: %.cpp $(INCLUDE)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean	
	rm -f ${NAME}

re: fclean all