/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:57:27 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/14 18:10:37 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_msg(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

static int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	return (0);
}

int	fdf_atoi(const char *str)
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
		exit_msg("Invaild Map!\n");
	while (ft_isdigit(str[i]))
		ret = ret * 10 + (str[i++] - '0');
	ret = ret * sign;
	if (ret > 2147483647 || ret < -2147483648)
		exit_msg("Invaild Map\n");
	return ((int)ret);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}