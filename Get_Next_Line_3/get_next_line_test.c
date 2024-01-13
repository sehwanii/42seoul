/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/02 15:38:57 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

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
// 	close( fd);
// }
static int check_left(char **word_left, char **ret_buf);

char	*get_next_line(int fd)
{
	char*		buf;
	int			size;
	char		*ret_buf;
	//char		*end;
	static char	*word_left;
	char * temp;

	ret_buf = NULL;
	buf = (char*)malloc(BUFFER_SIZE + 1);
	if(check_left(&word_left, &ret_buf))		//
		return (ret_buf);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if(check_left(&buf, &ret_buf)){
			word_left = buf;
			return(ret_buf);
		}
		if (ret_buf == NULL || ret_buf[0] == '\0')
			ret_buf = ft_strdup(buf);
		else{
			temp = ret_buf;
			ret_buf = ft_strjoin(ret_buf, buf);
			free(temp);
		}
	}
	if (size == -1){
		free(word_left);
		word_left = NULL;
	}
	return (ret_buf);
}


int check_left(char **word_left, char **ret_buf)
{
	char	*end;
	if (*word_left != NULL && (*word_left)[0] != '\0'){
		end = ft_strchr(*word_left, '\n');
		if (end){	//개행이 있다면
			*ret_buf = ft_strjoin(*ret_buf,ft_substr(*word_left, 0, end - *word_left + 1)); //뒷부분
			*word_left = ft_substr(*word_left, end - *word_left + 1, ft_strlen(*word_left) - (end - *word_left) - 1);//앞부분
			return (1);
		}
		else{ //없다면
			if(ret_buf)
				*ret_buf = ft_strjoin(*ret_buf,*word_left);
			else
				*ret_buf = ft_strdup(*word_left);
		}
	}
	// else{		//word_left == NULL이면
	// 	//free(*word_left);
	// 	*ret_buf = NULL;
	// }
	return (0);
}