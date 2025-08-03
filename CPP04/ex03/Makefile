NAME = main

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   AMateria.cpp \
	   Character.cpp \
	   MateriaSource.cpp \
	   Cure.cpp \
	   Ice.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
