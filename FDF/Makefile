# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/07/24 20:08:29 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME		= fdf
SRCS_FDF	= main.c read_map.c read_map_utils.c fdf_utils.c init_points.c draw.c draw_utils.c my_stoi.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c utils.c
OBJS_FDF	= $(SRCS_FDF:.c=.o)
OBJS_FDF_B	= $(SRCS_FDF_B:.c=.o)
SRCS_LIB	= $(LIBFTDIR)/ft_isalpha.c $(LIBFTDIR)/ft_lstdelone.c $(LIBFTDIR)/ft_memcmp.c $(LIBFTDIR)/ft_strdup.c $(LIBFTDIR)/ft_strnstr.c $(LIBFTDIR)/ft_atoi.c $(LIBFTDIR)/ft_isascii.c $(LIBFTDIR)/ft_memcpy.c $(LIBFTDIR)/ft_strlcat.c $(LIBFTDIR)/ft_strrchr.c $(LIBFTDIR)/ft_bzero.c $(LIBFTDIR)/ft_isdigit.c $(LIBFTDIR)/ft_memmove.c $(LIBFTDIR)/ft_strlcpy.c $(LIBFTDIR)/ft_tolower.c $(LIBFTDIR)/ft_calloc.c $(LIBFTDIR)/ft_isprint.c $(LIBFTDIR)/ft_memset.c $(LIBFTDIR)/ft_strlen.c $(LIBFTDIR)/ft_toupper.c $(LIBFTDIR)/ft_isalnum.c $(LIBFTDIR)/ft_memchr.c $(LIBFTDIR)/ft_strchr.c $(LIBFTDIR)/ft_strncmp.c $(LIBFTDIR)/ft_substr.c $(LIBFTDIR)/ft_strjoin.c $(LIBFTDIR)/ft_strtrim.c $(LIBFTDIR)/ft_split.c $(LIBFTDIR)/ft_itoa.c $(LIBFTDIR)/ft_strmapi.c $(LIBFTDIR)/ft_striteri.c $(LIBFTDIR)/ft_putchar_fd.c $(LIBFTDIR)/ft_putstr_fd.c $(LIBFTDIR)/ft_putendl_fd.c $(LIBFTDIR)/ft_putnbr_fd.c
LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft
MLXLIB		= ./minilibx/libmlx.dylib
MLXLIBDIR	= ./minilibx

OBJS_B = $(src_b:.c=.o)

# CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_B)
else
	OBJECTS = $(OBJS_FDF) 
endif

.PHONY : all clean fclean re bonus

all :
	make -C $(MLXLIBDIR)
	make $(NAME)

bonus : $(NAME_B)

$(NAME): $(OBJS_FDF) $(LIBFT)
	$(CC) $(OBJS_FDF) -framework Metal -framework Metalkit -I$(LIBFTDIR) $(LIBFT) -I$(MLXLIBDIR) $(MLXLIB) -o $(NAME)
	install_name_tool -change libmlx.dylib ./minilibx/libmlx.dylib fdf
	
# $(NAME_B) : $(OBJS_PS_B) $(LIBFT)
# 	$(CC)  $(OBJS_PS_B) -I$(LIBFTDIR) $(LIBFTDIR)/$(LIBFT) -o $(NAME)

$(LIBFT) : $(SRCS_LIB)
	make -C $(LIBFTDIR) bonus

%.o : %.c fdf.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJS_FDF) $(OBJS_B)
	@make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(MLXLIBDIR) clean

re : fclean all
