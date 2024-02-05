/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:17:21 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 19:44:20 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "push_swap.h"

void	ft_write(int fd, char *str)
{
	if (write(fd, str, ft_strlen(str)) == -1)
		exit(EXIT_FAILURE);
}

int	abs(int a)
{
	if (a == -2147483648)
		return (MAX_INT);
	if (a < 0)
		return (a * -1);
	return (a);
}
