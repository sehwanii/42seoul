# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/05/29 20:43:56 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	c++
NAME	=	ex01
SRCS	= 	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \

HEADERS	=	ClapTrap.hpp \
			ScavTrap.hpp \

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	= -Wall -Wextra -Werror -std=c++98

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
