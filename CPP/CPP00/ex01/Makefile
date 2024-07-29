# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/06/30 21:39:25 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= 	c++
NAME	=	phonebook
SRCS	= 	PhoneBook.cpp \
			Contact.cpp \
			main.cpp \

HEADERS	=	PhoneBook.hpp \
			Contact.hpp \

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	= -Wall -Wextra -Werror -std=c++98

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re : fclean all
