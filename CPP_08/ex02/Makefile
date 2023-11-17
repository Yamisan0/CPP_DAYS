SRCS = main.cpp

INCLUDE = MutantStack.hpp
FLAGS = -Wall -Wextra -Werror -g3
NAME = MutantStack
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