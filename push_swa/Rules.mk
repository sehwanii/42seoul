# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:58:48 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/25 23:58:50 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

ifdef DEBUG
		CFLAGS += -g
endif

link_files:: unlink_files
		@mkdir -p $(dst_dir);
		$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir);)

unlink_files::
		$(foreach file,$(files), $(RM) $(dst_dir)/$(file);)