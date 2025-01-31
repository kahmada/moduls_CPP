# These four classes don’t have to be designed in the Orthodox
# Canonical Form.

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = identifier
SRCS = Base.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Base.hpp A.hpp B.hpp C.hpp

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