CC = gcc
NAME = get_next_line.a
src_m = get_next_line_utils.c get_next_line.c


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
