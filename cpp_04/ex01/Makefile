NAME = animals

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = \
	main.cpp \
	Dog.cpp \
	Cat.cpp \
	Animal.cpp \
	Brain.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile Animal.h Dog.h Cat.h Brain.h
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
