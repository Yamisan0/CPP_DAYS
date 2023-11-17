SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

INCLUDE = Zombie.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombie
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