SRCS = main.cpp PmergeMe.cpp

INCLUDE = PmergeMe.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = PmergeMe
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
