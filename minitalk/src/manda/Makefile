# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 21:41:35 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/26 04:34:11 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

CLIENT = client
SERVER = server

clean fclean re:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(CLIENT) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(SERVER) $@

all:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(CLIENT) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(SERVER) $@

bonus:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(CLIENT) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(SERVER) $@

.PHONY: all clean fclean re bonus