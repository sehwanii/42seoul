/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line__.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/22 20:26:03 by sehwjang         ###   ########.fr       */
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
// 	int fd = open("input", O_RDONLY);
// 	if(fd<=0){
// 		printf("ERROR");
// 		return (0);
// 	}
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	close( fd);
// }
static int check_left(char **word_left, char **ret_buf);

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			size;
	char		*ret_buf;
	char		*end;
	static char	*word_left;
	char * temp;
	char	*temp2;
	temp2 = NULL;
	ret_buf = NULL;
	if(check_left(&word_left, &ret_buf))
		return (ret_buf);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		end = ft_strchr(buf, '\n');
		if (end)
		{
			if (ret_buf == NULL)
				ret_buf = ft_substr(buf, 0, end - buf + 1);
			else{
				temp = ret_buf;
				temp2 = ft_substr(buf, 0, end - buf + 1);
				ret_buf = ft_strjoin(temp, temp2);//leak
				free(temp2);
				if (ret_buf == NULL){
					free(temp);
					free(ret_buf);
				return (NULL);
				}
				free(temp);
			}
			free(word_left);
			//if(size != end - buf + 1)
			word_left = ft_substr(buf, end - buf + 1, size - (end - buf) - 1);//leak
			if (word_left == NULL){
				free(ret_buf);
				free(word_left);
				return (NULL);
			}
			break ;
		}
		if (ret_buf == NULL)
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
		if (end){
			*ret_buf = ft_substr(*word_left, 0, end - *word_left + 1);
			*word_left = ft_substr(*word_left, end - *word_left + 1, ft_strlen(*word_left) - (end - *word_left) - 1);
			return (1);
		}
		else{
			free(*ret_buf);
			*ret_buf = ft_strdup(*word_left);
			*word_left = NULL;
		}
	}
	else{
		//free(*word_left);
		*ret_buf = NULL;
	}
	return (0);
}
