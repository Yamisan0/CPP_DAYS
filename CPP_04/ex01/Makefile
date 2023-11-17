SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
INCLUDE = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 	
NAME = ex01
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