# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 21:41:35 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/25 21:41:36 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDA) $@

bonus:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) $@

.PHONY: all clean fclean re bonus