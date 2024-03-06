ifndef TOPDIR
        TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

LIBS =	libft\
		deque\
		my_utils\
		get_next_line\

all bonus clean fclean re:
	@$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)

.PHONY: all clean fclean re bonus