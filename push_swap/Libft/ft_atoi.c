/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:45:06 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 20:11:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static void	print_error(const char *error_msg);

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		print_error("ERROR\n");
	while (ft_isdigit(str[i]))
		ret = ret * 10 + (str[i++] - '0');
	ret = ret * sign;
	if (ret > 2147483647 || ret < -2147483648)
		print_error("ERROR\n");
	return ((int)(ret * sign));
}

static int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	return (0);
}

static void	print_error(const char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}
