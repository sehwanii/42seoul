# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/18 23:53:25 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = fdf
src_m =	main.c\
		read_map.c\
		fdf_utils.c\
		init_points.c\
		draw.c\
		my_stoi.c


OBJECTS = $(src_m:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : 
	make WITH_BONUS=1 all

$(NAME) : $(OBJECTS)
	ar rc $@ $^

%.o : %.c get_next_line.h
	$(CC) $(CFLAGS) -g3 -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re : fclean all
