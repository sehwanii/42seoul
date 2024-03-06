/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:04:53 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/20 01:55:10 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

#define MAX_INT	2147483647
#define MIN_INT	-2147483648

static int	str_h_to_i(char *s);
static int	str_b_to_i(char *s);
static int	str_d_to_i(char *s);

int	my_stoi(char *str)
{
	int	sign;
	int	ret;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		ret = str_h_to_i(str + 2);
	else if (*str == '0' && *(str + 1) == 'b')
		ret = str_b_to_i(str + 2);
	else
		ret = str_d_to_i(str);
	if (ret == MIN_INT && sign == -1)
		write(2, "ERROR : INT UNDERFLOW -> my_stoi()\n", 36);
	return (ret * sign);
}

static int	str_d_to_i(char *s)
{
	int		idx;
	long	ret;

	idx = 0;
	ret = 0;
	while (s[idx] >= '0' && s[idx] <= '9')
	{
		ret = ret * 10 + (s[idx++] - '0');
		if (ret > MAX_INT)
			write(2, "ERROR : INT OVERFLOW -> my_stoi()\n", 35);
	}
	return ((int)ret);
}

static int	str_b_to_i(char *s)
{
	int		idx;
	long	ret;

	idx = 0;
	ret = 0;
	while (s[idx] == '0' || s[idx] == '1')
	{
		ret = ret * 2 + (s[idx++] - '0');
		if (ret > MAX_INT)
			write(2, "ERROR : INT OVERFLOW -> my_stoi()\n", 35);
	}
	return ((int)ret);
}

static int	str_h_to_i(char *s)
{
	int			i;
	int			j;
	long		ret;
	const char	*o_alphabet = "0123456789abcdefABCDEF";

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != o_alphabet[j])
			j++;
		if (j == 24)
			break ;
		else if (j <= 15)
			ret = ret * 16 + j;
		else
			ret = ret * 16 + (j - 6);
		if (ret > MAX_INT)
			write(2, "ERROR : INT OVERFLOW -> my_stoi()\n", 35);
		i++;
	}
	return ((int)ret);
}
