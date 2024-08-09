# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/23 15:42:45 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME		= fdf
NAME_B		= checker
SRCS_FDF	= main.c read_map.c fdf_utils.c init_points.c draw.c draw_utils.c my_stoi.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS_FDF	= $(SRCS_FDF:.c=.o)
OBJS_FDF_B	= $(SRCS_FDF_B:.c=.o)
SRCS_LIB	= $(SUB_LIBDIR)/ft_isalpha.c $(SUB_LIBDIR)/ft_memcmp.c $(SUB_LIBDIR)/ft_strdup.c $(SUB_LIBDIR)/ft_strnstr.c $(SUB_LIBDIR)/ft_atoi.c $(SUB_LIBDIR)/ft_isascii.c $(SUB_LIBDIR)/ft_memcpy.c $(SUB_LIBDIR)/ft_strlcat.c $(SUB_LIBDIR)/ft_strrchr.c $(SUB_LIBDIR)/ft_bzero.c $(SUB_LIBDIR)/ft_isdigit.c $(SUB_LIBDIR)/ft_memmove.c $(SUB_LIBDIR)/ft_strlcpy.c $(SUB_LIBDIR)/ft_tolower.c $(SUB_LIBDIR)/ft_calloc.c $(SUB_LIBDIR)/ft_isprint.c $(SUB_LIBDIR)/ft_memset.c $(SUB_LIBDIR)/ft_strlen.c $(SUB_LIBDIR)/ft_toupper.c $(SUB_LIBDIR)/ft_isalnum.c $(SUB_LIBDIR)/ft_memchr.c $(SUB_LIBDIR)/ft_strchr.c $(SUB_LIBDIR)/ft_strncmp.c $(SUB_LIBDIR)/ft_substr.c $(SUB_LIBDIR)/ft_strjoin.c $(SUB_LIBDIR)/ft_strtrim.c $(SUB_LIBDIR)/ft_split.c $(SUB_LIBDIR)/ft_itoa.c $(SUB_LIBDIR)/ft_strmapi.c $(SUB_LIBDIR)/ft_striteri.c $(SUB_LIBDIR)/ft_putchar_fd.c $(SUB_LIBDIR)/ft_putstr_fd.c $(SUB_LIBDIR)/ft_putendl_fd.c $(SUB_LIBDIR)/ft_putnbr_fd.c
SUB_LIB		= libft.a
SUB_LIBDIR	= ./Libft
OBJS_B = $(src_b:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_B)
else
	OBJECTS = $(OBJS_FDF) 
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : $(NAME_B)

$(NAME): $(OBJS_FDF) $(SUB_LIB)
	$(CC) $(OBJS_FDF) -framework OpenGL -framework AppKit -I$(SUB_LIBDIR) $(SUB_LIBDIR)/$(SUB_LIB) -I ./minilibx ./minilibx/libmlx.dylib  -o $(NAME)

# $(NAME_B) : $(OBJS_PS_B) $(SUB_LIB)
# 	$(CC)  $(OBJS_PS_B) -I$(SUB_LIBDIR) $(SUB_LIBDIR)/$(SUB_LIB) -o $(NAME)

$(SUB_LIB) : $(SRCS_LIB)
	make -C $(SUB_LIBDIR) bonus

%.o : %.c fdf.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJS_FDF) $(OBJS_B)
	@make -C $(SUB_LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(SUB_LIBDIR) fclean

re : fclean all
