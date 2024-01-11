/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:03:39 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/11 15:22:29 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "Libft/libft.h"

int		ft_printf(const char *format, ...);
size_t	print_format(char type, va_list ap);
int		ft_print_memory(void *addr);
int		write_char(char c);
int		write_string(char *s);
int		write_int(int n);
int		write_unsigned_int(unsigned int n);
int		write_hex(unsigned int n, int flag);
int		write_big_hex(unsigned int n, int flag);
#endif