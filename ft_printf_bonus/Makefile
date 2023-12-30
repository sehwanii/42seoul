CC = cc
NAME = libft_printf.a
src_m = ft_printf.c utils.c ft_print_memory.c test.c
src_b = ft_printf_bonus.c
OBJS = $(src_m:.c=.o)
OBJS_B = $(src_b:.c=.o)

CFLAGS = -Wall -Wextra -

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_B)
else
	OBJECTS = $(OBJS) 
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : 
	make WITH_BONUS=1 all

$(NAME) : $(OBJECTS)
	make -C ./Libft bonus
	cp ./Libft/libft.a libft.a 
	ar rc $@ $^
	

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)
	make -C ./Libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f ./Libft/libft.a

re : fclean all
