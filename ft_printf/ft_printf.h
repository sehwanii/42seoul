/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:03:39 by sehwjang          #+#    #+#             */
/*   Updated: 2023/12/30 21:41:10 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <stdio.h>

# define MINUS	1
# define ZERO	2
# define DOT	4
# define PLUS	8
# define HASH	16
# define SPACE	32

# define INT_MAX	2147483647

# define TRUE	1
# define FALSE	-1

int		ft_printf(const char *format, ...);
size_t	print_format(char type, va_list ap);

int	ft_print_memory(void *addr);

int	write_char(char c);
int	write_string(char *s);
int	write_int(int n);
int	write_hex(int n);
int	write_HEX(int n);
#endif