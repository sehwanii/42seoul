ifndef TOPDIR
	TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

MANDA = manda
BONUS = bonus

clean fclean re:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDA) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) $@

all:
	@echo a
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDA) $@

bonus:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) $@

.PHONY: all clean fclean re bonus