ifndef TOPDIR
        TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

LIBS =	libft\
		ft_printf\
		get_next_line\
		my_utils

all bonus clean fclean re:
	@$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)
#libft 같은 경우는 계속 보너스로 해줘야하는데


.PHONY: all clean fclean re bonus