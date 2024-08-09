/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:33:33 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/29 21:31:58 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long long n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static long long	change_to_pos(int n, int *sign)
{
	long long	num;

	if (n < 0)
	{
		*sign = 1;
		num = (long long)n * -1;
	}
	else
		num = (long long)n;
	return (num);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			sign;
	char		*ret;
	int			idx;
	int			n_len;

	sign = 0;
	idx = 0;
	num = change_to_pos(n, &sign);
	n_len = num_len(num);
	ret = (char *)malloc(n_len + sign + 1);
	if (ret == NULL)
		return (0);
	if (sign)
		ret[0] = '-';
	ret[n_len + sign] = '\0';
	while (idx < n_len)
	{
		ret[n_len + sign - idx++ -1] = num % 10 + '0';
		num /= 10;
	}
	return (ret);
}
