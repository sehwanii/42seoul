/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:36 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/10 16:55:58 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(char *s)
{
	size_t	idx;
	char	*temp;

	if (s == NULL)
	{
		temp = "(null)";
		write(1, temp, 6);
		return (6);
	}
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

int	write_unsigned_int(unsigned int n)
{
	char	arr[11];
	int		pow;
	int		ret;

	ret = 0;
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

int	write_hex(unsigned int n)
{
	int		idx;
	char	*hex;

	hex = "0123456789abcdef";
	idx = 0;
	while (n > 0)
	{
		idx += write_hex(n / 16);
		write(1, &hex[n % 16], 1);
		return (1 + idx);
	}
	return (0);
}

int	write_HEX(unsigned int n)
{
	int		idx;
	char	*hex;

	hex = "0123456789ABCDEF";
	idx = 0;
	while (n > 0)
	{
		idx += write_HEX(n / 16);
		write(1, &hex[n % 16], 1);
		return (1 + idx);
	}
	return (0);
}