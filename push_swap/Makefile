# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/01/25 00:14:41 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap.a
src_m = push_swap.c push_swap_utils.c
OBJS = $(src_m:.c=.o)
OBJS_B = $(src_b:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./Libft bonus
	make -C ./Deque all
	cp ./Deque/deque.a $(NAME)
	cp ./Libft/libft.a $(NAME)
	ar rc $@ $^
	
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)
	make -C ./Libft clean
	make -C ./Deque clean

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a
	rm -f ./Deque/deque.a

re : fclean all
