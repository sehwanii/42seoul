# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/01/24 13:33:02 by sehwjang         ###   ########.fr        #
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
	cp ./Libft/libft.a $(NAME)
	ar rc $@ $^
	
%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)
	make -C ./Libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re : fclean all
