/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:03:39 by sehwjang          #+#    #+#             */
/*   Updated: 2023/12/23 10:14:54 by sehwjang         ###   ########.fr       */
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

typedef struct s_data
{
	char	flag;
	size_t	width;
	size_t	precision;
	size_t	length;
	char	*str;
	char	type;
}t_data;

int	ft_printf(const char *format, ...);
char	is_type(char c);
void parse_format(const char* format, t_list **head);
t_list	*init_data(char *str, char type);
char	is_flag(char c);
size_t	print_format(const char* str, va_list ap, t_list *head);

int	ft_print_memory(void *addr);

int write_char(char c);
int	write_string(char *s);
int	write_int(int n);
#endif