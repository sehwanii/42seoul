CC = cc
NAME = libftprintf.a
src_m = ft_printf.c ft_print_memory.c print_format.c
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
