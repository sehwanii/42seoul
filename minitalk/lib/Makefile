ifndef TOPDIR
        TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

LIBS =	libft\
		my_utils\
		deque\
		ft_printf\

all bonus clean fclean re:
	@$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)

.PHONY: all clean fclean re bonus