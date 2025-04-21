CPP = c++

CPPFLAGS = -Wall -Wextra -Werror 

NAME = PmergeMe

SRCS = PmergeMe.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = PmergeMe.hpp

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