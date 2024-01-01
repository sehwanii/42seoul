/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/01 18:59:55 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE

# define BUFFER_SIZE 1
#endif
// int	main()
// {
// 	int fd = open( "./input.txt",O_RDWR);
// 	if(fd<=0)
// 		printf("ERROR");
// 	printf("result : ");
// 	while(printf("%s",get_next_line(fd)));

// 	close( fd);
// }

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			size;
	char		*ret_buf;
	char		*end;
	static char	*word_left;

	if (word_left != NULL)
		ret_buf = ft_strdup(word_left);
	else
		ret_buf = NULL;
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		end = ft_strchr(buf, '\n');
		if (end)
		{
			if (ret_buf == NULL)
				ret_buf = ft_substr(buf, 0, end - buf + 1);
			else
				ret_buf = ft_strjoin(ret_buf, ft_substr(buf, 0, end - buf + 1));
			word_left = ft_substr(buf, end - buf + 2, size - (end - buf));
			return (ret_buf);
		}
		if (ret_buf == NULL)
			ret_buf = ft_strdup(buf);
		else
			ret_buf = ft_strjoin(ret_buf, buf);
	}
	close(fd);
	return (ret_buf);
}
