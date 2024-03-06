# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/25 06:20:51 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

CPPFLAGS = -I$(TOPDIR)/include

NAME = libgetnextline.a

HEAD = fdf.h
SRCS =	main.c\
		draw.c\
		fdf_utils.c\
		init_points.c\
		read_map.c

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

# LDLIBS :=	-lft \
# 			-lgetnextline \
# 			-ldeque \

# LDFLAGS :=	-L$(TOPDIR)/lib

# all bonus: $(NAME)

# $(NAME): $(OBJS)
# 	$(LINK.o) $^  $(LDFLAGS) $(LDLIBS) -o $@
# # $(AR) $(ARFLAGS) $@ $^
# 	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) link_files
# # $(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files

# clean:
# 	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
# # $(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include unlink_files
# 	$(RM) $(OBJS) $(DEPS)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean
# 	$(MAKE) all

# .PHONY: all clean fclean re bonus