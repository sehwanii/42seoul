CC = cc
NAME = deque.a
src_m = deque.c deque_pop.c deque_get.c deque_add.c


OBJECTS = $(src_m:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)


$(NAME) : $(OBJECTS)
	@ar rc $@ $^

%.o : %.c deque.h
	@$(CC) $(CFLAGS) -g3 -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(OBJS_B)
	echo "clean deque"
	
fclean: clean
	@rm -f $(NAME)
	echo "fclean deque"

re : fclean all
