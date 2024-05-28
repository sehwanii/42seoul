# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/05/26 17:05:31 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME			=	philo
NAME_B			=	philo_bonus
SRCS_PHILO		= 	main.c \
					utils.c \
					init.c \
					philo.c \
					philo_action.c \
					philo_time.c \

SRCS_PHILO_B	=	main.c \

OBJS_PHILO		=	$(SRCS_PHILO:.c=.o)
OBJS_PHILO_B	=	$(SRCS_PHILO_B:.c=.o)
OBJS_B			=	$(src_b:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_B)
else
	OBJECTS = $(OBJS_PHILO)
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : $(NAME_B)

$(NAME): $(OBJS_PHILO)
	$(CC) $(OBJS_PHILO) -o $(NAME)

# $(NAME_B) : $(OBJS_PS_B) $(SUB_LIB)
# 	$(CC)  $(OBJS_PS_B) -I$(SUB_LIBDIR) $(SUB_LIBDIR)/$(SUB_LIB) -o $(NAME)

%.o : %.c philo.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJS_PHILO) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re : fclean all
