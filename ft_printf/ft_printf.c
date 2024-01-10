/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:53 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/10 17:02:43 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	size_t	idx;
	size_t	word_start;
	char	*temp;

	va_start(ap, format);
	word_start = 0;
	len = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			temp = ft_substr(format, word_start, idx - word_start);
			len += ft_putstr_fd(temp, 1) + print_format(format[idx++ + 1], ap);
			free(temp);
			word_start = idx + 1;
		}
		idx++;
	}
	temp = ft_substr(format, word_start, idx - word_start);
	len += ft_putstr_fd(temp, 1);
	free(temp);
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
		return (write_hex(va_arg(ap, int)));
	else if (type == 'X')
		return (write_HEX(va_arg(ap, int)));
	else
		return (-1);
	return (1);
}

int	write_char(char c)
{
	return (write(1, &c, 1));
}

// int main(){
// 	printf("\n%d",ft_printf("%x", 0));
// }