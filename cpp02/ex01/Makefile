# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 20:21:28 by kahmada           #+#    #+#              #
#    Updated: 2024/11/29 20:21:31 by kahmada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp Fixed.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(NAME)
fclean: clean
	rm -f $(NAME)

re: fclean all
