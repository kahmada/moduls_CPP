CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = burau

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Array.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all