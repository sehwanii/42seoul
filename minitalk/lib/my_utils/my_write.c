/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:00:20 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 20:07:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

void	exit_msg(const char *msg)
{
	ft_write(2, msg);
	exit(EXIT_FAILURE);
}

void	ft_write(int fd, const char *str)
{
	if (write(fd, str, ft_strlen(str)) == -1)
		exit(EXIT_FAILURE);
}
