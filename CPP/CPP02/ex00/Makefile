# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/08/22 17:41:32 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	c++
NAME	=	ex00
SRCS	= 	main.cpp \
			Fixed.cpp \

HEADERS	=	Fixed.hpp \

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	= -Wall -Wextra -Werror -std=c++98

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFAGS) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
