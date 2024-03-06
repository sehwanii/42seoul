/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:36 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/11 15:26:56 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(char *s)
{
	size_t	idx;
	char	*n_string;
	int		temp;

	temp = 0;
	if (s == NULL)
	{
		n_string = "(null)";
		temp = write(1, n_string, 6);
		return (temp);
	}
	idx = 0;
	while (s[idx])
	{
		temp = write(1, &s[idx++], 1);
		if (temp == -1)
			return (-1);
	}
	return (idx);
}

int	write_int(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (write_unsigned_int(-n) + 1);
	}
	return (write_unsigned_int(n));
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
		if (write(1, arr + pow-- - 1, 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}

int	write_hex(unsigned int n, int flag)
{
	int		idx;
	char	*hex;
	int		temp;

	temp = 0;
	if (flag == 0 && n == 0)
		return (write(1, "0", 1));
	hex = "0123456789abcdef";
	idx = 0;
	while (n > 0)
	{
		temp = write_hex(n / 16, 1);
		if (temp == -1)
			return (-1);
		idx += temp;
		if (write(1, &hex[n % 16], 1) == -1)
			return (-1);
		return (1 + idx);
	}
	return (0);
}

int	write_big_hex(unsigned int n, int flag)
{
	int		idx;
	char	*hex;
	int		temp;

	temp = 0;
	if (flag == 0 && n == 0)
		return (write(1, "0", 1));
	hex = "0123456789ABCDEF";
	idx = 0;
	while (n > 0)
	{
		temp = write_big_hex(n / 16, 1);
		if (temp == -1)
			return (-1);
		idx += temp;
		if (write(1, &hex[n % 16], 1) == -1)
			return (-1);
		return (1 + idx);
	}
	return (0);
}
