# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/05 20:21:30 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME		= push_swap
NAME_B		= checker
SRCS_PS		= main.c push_swap.c push_swap_init.c my_utils.c push_swap_utils.c push_swap_op_p.c push_swap_op_r.c push_swap_op_rr.c push_swap_op_s.c push_swap_small.c ./Deque/deque_add.c ./Deque/deque_get.c ./Deque/deque_pop.c ./Deque/deque.c
SRCS_PS_B	= checker.c push_swap_op_p.c push_swap_op_r.c push_swap_op_rr.c push_swap_op_s.c push_swap_small.c ./Deque/deque_add.c ./Deque/deque_get.c ./Deque/deque_pop.c ./Deque/deque.c
OBJS_PS		= $(SRCS_PS:.c=.o)
OBJS_PS_B	= $(SRCS_PS_B:.c=.o)
SRCS_LIB	= $(SUB_LIBDIR)/ft_isalpha.c $(SUB_LIBDIR)/ft_memcmp.c $(SUB_LIBDIR)/ft_strdup.c $(SUB_LIBDIR)/ft_strnstr.c $(SUB_LIBDIR)/ft_atoi.c $(SUB_LIBDIR)/ft_isascii.c $(SUB_LIBDIR)/ft_memcpy.c $(SUB_LIBDIR)/ft_strlcat.c $(SUB_LIBDIR)/ft_strrchr.c $(SUB_LIBDIR)/ft_bzero.c $(SUB_LIBDIR)/ft_isdigit.c $(SUB_LIBDIR)/ft_memmove.c $(SUB_LIBDIR)/ft_strlcpy.c $(SUB_LIBDIR)/ft_tolower.c $(SUB_LIBDIR)/ft_calloc.c $(SUB_LIBDIR)/ft_isprint.c $(SUB_LIBDIR)/ft_memset.c $(SUB_LIBDIR)/ft_strlen.c $(SUB_LIBDIR)/ft_toupper.c $(SUB_LIBDIR)/ft_isalnum.c $(SUB_LIBDIR)/ft_memchr.c $(SUB_LIBDIR)/ft_strchr.c $(SUB_LIBDIR)/ft_strncmp.c $(SUB_LIBDIR)/ft_substr.c $(SUB_LIBDIR)/ft_strjoin.c $(SUB_LIBDIR)/ft_strtrim.c $(SUB_LIBDIR)/ft_split.c $(SUB_LIBDIR)/ft_itoa.c $(SUB_LIBDIR)/ft_strmapi.c $(SUB_LIBDIR)/ft_striteri.c $(SUB_LIBDIR)/ft_putchar_fd.c $(SUB_LIBDIR)/ft_putstr_fd.c $(SUB_LIBDIR)/ft_putendl_fd.c $(SUB_LIBDIR)/ft_putnbr_fd.c
SUB_LIB		= libft.a
SUB_LIBDIR	= ./Libft
OBJS_B = $(src_b:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_B)
else
	OBJECTS = $(OBJS) 
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJS_PS) $(SUB_LIB)
	$(CC) -g3 $(OBJS_PS) -I$(SUB_LIBDIR) $(SUB_LIBDIR)/$(SUB_LIB) -o $(NAME)

$(NAME_B) : $(OBJS_PS_B) $(SUB_LIB)
	$(CC) -g3 $(OBJS_PS_B) -I$(SUB_LIBDIR) $(SUB_LIBDIR)/$(SUB_LIB) -o $(NAME)

$(SUB_LIB) : $(SRCS_LIB)
	make -C $(SUB_LIBDIR) bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_PS) $(OBJS_B)
	@make -C $(SUB_LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(SUB_LIBDIR) fclean

re : fclean all
