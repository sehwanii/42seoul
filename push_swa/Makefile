# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 23:58:54 by sehwjang          #+#    #+#              #
#    Updated: 2024/02/25 23:58:56 by sehwjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Rules.mk

MANDA = manda
BONUS = bonus

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus