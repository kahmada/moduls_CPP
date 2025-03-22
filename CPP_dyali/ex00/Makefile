CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = btc

SRCS = BitcoinExchange.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = BitcoinExchange.hpp

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