/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:53 by sehwjang          #+#    #+#             */
/*   Updated: 2023/12/30 21:41:50 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	size_t	idx;
	size_t	word_start;

	va_start(ap, format);
	word_start = 0;
	len = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			ft_putstr_fd(ft_substr(format, word_start, idx - word_start), 1);
			print_format(format[idx++ + 1], ap);
			word_start = idx + 1;
		}
		idx++;
	}
	return (len);
}

size_t	print_format(char type, va_list ap)
{
	if (type == 'c')
		write_char((char)va_arg(ap, int));
	else if (type == 's')
		write_string((char *)va_arg(ap, char *));
	else if (type == 'p')
		ft_print_memory((void *)va_arg(ap, void *));
	else if (type == 'd')
		write_int(va_arg(ap, int));
	else if (type == '%')
		write(1, "%%", 1);
	else if (type == 'i')
		write_int(va_arg(ap, int));
	else if (type == 'u')
		write_int((unsigned int)va_arg(ap, int));
	else if (type == 'x')
		write_hex(va_arg(ap, int));
	else if (type == 'X')
		write_HEX(va_arg(ap, int));
	else
		return (-1);
	return (1);
}

int	write_char(char c)
{
	return (write(1, &c, 1));
}

int	write_string(char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		write(1, &s[idx++], 1);
	return (idx);
}

int	write_int(int n)
{
	char	arr[11];
	int		pow;
	int		ret;

	ret = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		ret++;
		n *= -1;
	}
	pow = 0;
	while (n > 0 || pow == 0)
	{
		arr[pow++] = '0' + n % 10;
		n /= 10;
	}
	while (pow >= 1)
	{
		write(1, arr + pow-- - 1, 1);
		ret++;
	}
	return (ret);
}

int	write_hex(int n)
{
	int		idx;
	char	*hex;
	char	arr[2];

	hex = "0123456789abcdef";
	idx = 0;
	while (idx < 2)
	{
		arr[1 - idx] = hex[n % 16];
		n /= 16;
		idx++;
	}
	if (arr[0] == '0')
		return (write(1, &arr[1], 1));
	else
		return (write(1, arr, 2));
}

int	write_HEX(int n)
{
	int		idx;
	char	*hex;
	char	arr[2];

	hex = "0123456789abcdef";
	idx = 0;
	while (idx < 2)
	{
		arr[1 - idx] = hex[n % 16];
		n /= 16;
		idx++;
	}
	if (arr[0] == '0')
		return (write(1, &arr[1], 1));
	else
		return (write(1, arr, 2));
}

int main(){
	ft_printf("asdf %% %d",123);
}