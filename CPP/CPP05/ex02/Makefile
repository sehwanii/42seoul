# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/12/26 18:58:19 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	c++
NAME	=	ex02
SRCS	= 	$(wildcard *.cpp)

HEADERS	=	$(wildcard *.hpp)

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
