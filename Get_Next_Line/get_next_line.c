/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/31 13:34:49 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 1

int	main(int argc, char **argv)
{
	if (argc == 1)
	
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		temp_read_size;
	char	*save;

	temp_read_size = read(fd, buf, BUFFER_SIZE);
	while ((temp_read_size) > 0)
	{
		buf[temp_read_size] = '\0';
		if (save == NULL)
			save = strdup(buf);
		else
			strcat(save, buf);
		temp_read_size = read(fd, buf, BUFFER_SIZE);
	}
	printf("%s", save);
	//close(fd);
}




