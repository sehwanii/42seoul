/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:01:22 by sehwjang          #+#    #+#             */
/*   Updated: 2023/12/23 11:02:03 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (c);
	else if(c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (c);
	else
		return (0);
}

char	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.')
		return (c);
	else if(c == '#' || c == ' ' || c == '+')
		return (c);
	else if (ft_isdigit(c))
		return (c);
	else
		return (0);
}
