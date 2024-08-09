/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:33:23 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/28 16:41:18 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[11];
	int		pow;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
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
		write(fd, arr + pow - 1, 1);
		pow--;
	}
}
