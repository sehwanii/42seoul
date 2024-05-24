/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:47:05 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/26 08:56:25 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	return (0);
}

int	my_atoi(const char *str)
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
		exit_msg("Invalid Argument\n");
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + (str[i++] - '0');
		if ((ret * sign) > 2147483647 || (ret * sign) < -2147483648)
			exit_msg("Error : Arguments Overflow\n");
	}
	if (str[i] != '\0')
		exit_msg("Invalid Argument\n");
	ret = ret * sign;
	return ((int)ret);
}

void	exit_msg(const char *msg)
{
	if (write(2, msg, ft_strlen(msg)) == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	return (cnt);
}