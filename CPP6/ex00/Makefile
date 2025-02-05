CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert
SRCS = cast.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = cast.hpp

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