# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:31:59 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/26 00:01:25 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

CPPFLAGS = -I$(TOPDIR)/include

NAME = checker
SRCS =	main.c\
		checker.c\
		push_swap_init.c\
		push_swap_op_p.c\
		push_swap_op_r.c\
		push_swap_op_rr.c\
		push_swap_op_s.c\
		my_utils.c\


LDLIBS :=	-lft \
			-ldeque \
			-lmyutils \

LDFLAGS :=	-L$(TOPDIR)/lib

bonus: $(NAME)

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