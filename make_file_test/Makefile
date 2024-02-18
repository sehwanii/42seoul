include Rules.mk

MANDA = manda
BONUS = bonus

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus