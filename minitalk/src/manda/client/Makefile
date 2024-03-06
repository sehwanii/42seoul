# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/03/02 20:40:53 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

CPPFLAGS = -I$(TOPDIR)/include

NAME = 	client
SRCS =	client.c\


LDLIBS :=	-lft \
			-lmyutils \
			-lftprintf \

LDFLAGS :=	-L$(TOPDIR)/lib

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK.o) $^  $(LDFLAGS) $(LDLIBS) -o $@
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) link_files

clean:
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus