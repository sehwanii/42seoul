# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 20:53:33 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/18 22:32:33 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

CPPFLAGS = -I$(TOPDIR)/include

NAME = libgetnextline.a

HEAD = get_next_line.h
SRCS = get_next_line_utils.c get_next_line.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files

clean:
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib unlink_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include unlink_files
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
