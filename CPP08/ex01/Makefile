CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = spam

SRCS = main.cpp span.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = span.hpp

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