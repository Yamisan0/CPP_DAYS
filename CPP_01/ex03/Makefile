SRCS = main.cpp Weapon.cpp  HumanA.cpp HumanB.cpp

INCLUDE = Weapon.hpp HumanB.hpp HumanA.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = violence
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