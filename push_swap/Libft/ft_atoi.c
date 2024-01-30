/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:45:06 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/30 03:23:55 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

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
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		exit(EXIT_FAILURE);
	while (ft_isdigit(str[i]))
		ret = ret * 10 + (str[i++] - '0');
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
