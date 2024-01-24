/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/24 14:47:47 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

// int	main(void)
// {
// 	const int	fd = open("./input.txt", O_RDWR);

// 	if (fd <= 0)
// 	{
// 		printf("ERROR");
// 		return (0);
// 	}
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	const size_t	prefix_len = ft_strlen(s1);
	const size_t	suffix_len = ft_strlen(s2);
	const size_t	total_len = prefix_len + suffix_len;
	char			*ret_str;
	size_t			idx;

	idx = 0;
	ret_str = (char *)malloc(total_len + 1);
	if (ret_str == NULL)
		return (0);
	while (idx < prefix_len)
	{
		ret_str[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (idx < suffix_len)
	{
		ret_str[prefix_len + idx] = s2[idx];
		idx++;
	}
	ret_str[total_len] = '\0';
	free(s1);
	free(s2);
	return (ret_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	if (s == NULL)
		return (0);
	cnt = 0;
	while ((s[cnt]))
		cnt++;
	return (cnt);
}

char	*ft_realloc(char *s)
{
	char			*ret;
	const size_t	size = ft_strlen(s);
	size_t			idx;

	idx = 0;
	if (s == NULL || *s == '\0' || size == 0){
		free(s);
		return (NULL);
	}
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	while (idx < size)
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	free(s);
	return (ret);
}

int	parse_buffer(char* s, char **ret, char *line)
{
	const size_t	s_len = ft_strlen(s);
	const size_t	ret_len = ft_strlen(*ret);
	size_t			idx;

	idx = 0;
	if (*ret == NULL)
		*ret = (char *)malloc(BUFFER_SIZE + 1);
	while (idx < s_len)
	{
		(*ret)[ret_len + idx] = s[idx];
		if (s[idx++] == '\n')
		{
			(*ret)[ret_len + idx] = '\0';
			while (idx <= s_len)
				*(line++) = s[idx++];
			return (0);
		}
	}
	s[0] = '\0';
	(*ret)[s_len + ret_len] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			size;

	ret = NULL;
	if (fd < 0)
		return (NULL);
	if (line[0] != '\0' && parse_buffer(line, &ret, line) == 0)	//malloc 안되엇을 때, buffer에 개행 있을 때 
		return (ft_realloc(ret));
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buffer[size] = '\0';
	//if (size != BUFFER_SIZE)	//파일 마지막이라면
	if (parse_buffer(buffer, &ret, line) == 0)	//malloc 안되엇을 때, buffer에 개행 있을 때 
		return (ft_realloc(ret));
	ret = ft_strjoin(ret, get_next_line(fd));
	//printf("!%s!\n",ret);
	return (ft_realloc(ret));
}


