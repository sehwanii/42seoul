/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:16:34 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/21 02:55:17 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	init_buffer(char *check_buf, char **left, char **right)
{
	int		idx;
	int		len;
	char	*temp;
	int		flag;
char * temp2 = NULL;
	flag = 0;
	idx = 0;
	len = 0;
	temp = NULL;
	while (check_buf[len])
		len++;
	while (check_buf[idx])
	{
		if (check_buf[idx] == '\n'){
			flag = 1;
			break ;
		}
		idx++;
	}
	temp = ft_substr(check_buf, 0, idx + 1);
	if (temp == NULL)
		return (-1);
	if (flag)
	{
		temp2 = *left;		//left == NULL일 때 처리.
		*left = ft_strjoin(temp2, temp);
		free(temp);
		free(temp2);
		*right = ft_substr(check_buf, idx + 1, len - idx);
		if (*right == NULL)
		{
			free(temp);
			return (-1);
		}
		return (1);
	}
	
	temp2 = *left;
	*left = ft_strjoin(temp2, temp);
	free(temp2);
	free(temp);
	return (0);
}



char	*get_next_line(int fd)
{
	static char	*prev_buf;
	char		*ret_buf = NULL;
	int			size;
	char		buf[BUFFER_SIZE + 1];

	size = 0;
	if (prev_buf == NULL || *prev_buf == '\0')
		ret_buf = NULL;
	else if (init_buffer(prev_buf, &ret_buf, &prev_buf) == 1)
		return (ret_buf);
	else
	{
		ret_buf = ft_strdup(prev_buf);
		free(prev_buf);
	}
	size = read(fd, buf, BUFFER_SIZE);
	while ((size) > 0)
	{
		buf[size] = '\0';
		if (init_buffer(buf, &ret_buf, &prev_buf))
			return (ret_buf);
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (ret_buf);
}

// int	main()
// {
// 	int fd = open( "./input.txt",O_RDWR);
// 	if(fd<=0){
// 		printf("ERROR");
// 		return (0);
// 	}
// 	printf("%s",get_next_line(fd));
// printf("%s",get_next_line(fd));
// printf("%s",get_next_line(fd));
// printf("%s",get_next_line(fd));
// printf("%s",get_next_line(fd));
// printf("%s",get_next_line(fd));
// printf("%s",get_next_line(fd));
// 	close( fd);
// }