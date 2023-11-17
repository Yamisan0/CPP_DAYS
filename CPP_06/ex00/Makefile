SRCS = main.cpp ScalarConverter.cpp

INCLUDE = ScalarConverter.hpp

FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = Scalar
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
	rm -f ShrubberyCreationForm_shrubbery

re: fclean all