/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:53 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/13 14:55:03 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			len;
	size_t			idx;
	int				temp;
	const size_t	format_len = ft_strlen(format);

	va_start(ap, format);
	len = 0;
	idx = 0;
	while (idx < format_len)
	{
		if (format[idx] == '%')
		{
			temp = print_format(format[idx + 1], ap);
			idx += 2;
		}
		else
			temp = write(1, &format[idx++], 1);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	return (len);
}

size_t	print_format(char type, va_list ap)
{
	if (type == 'c')
		return (write_char((char)va_arg(ap, int)));
	else if (type == 's')
		return (write_string((char *)va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_print_memory((void *)va_arg(ap, void *)));
	else if (type == 'd')
		return (write_int(va_arg(ap, int)));
	else if (type == '%')
		return (write(1, "%%", 1));
	else if (type == 'i')
		return (write_int(va_arg(ap, int)));
	else if (type == 'u')
		return (write_unsigned_int(va_arg(ap, int)));
	else if (type == 'x')
		return (write_hex(va_arg(ap, int), 0));
	else if (type == 'X')
		return (write_big_hex(va_arg(ap, int), 0));
	else
	{
		if (write(1, "%%", 1) + write(1, &type, 1) != 2)
			return (-1);
		return (2);
	}
}

int	write_char(char c)
{
	return (write(1, &c, 1));
}
