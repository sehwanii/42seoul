/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/24 21:57:07 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif


void populate_expected(char *buffer, int n)
{
	int i = 0;
	while(i < n)
	{
		i += sprintf(buffer + i, "0123456789");
	}
	buffer[n] = 0;
}

int	main(void)
{

	int fd = open("input.txt", O_RDONLY);
	char expected[20000 + 1];
	populate_expected(expected, 20000);
	//fd = open("./input.txt", O_RDWR);

	if (fd <= 0)
	{
		printf("ERROR");
		return (0);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);

}

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
		return (NULL);
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

int	parse_buffer(char* s, char **ret, char *line)
{
	const size_t	s_len = ft_strlen(s);
	size_t			idx;
	char			*temp;

	idx = 0;
	if (*ret == NULL)
	{
		*ret = (char *)malloc(BUFFER_SIZE + 1);
		if (*ret == NULL)
			return (0);
		**ret = '\0';
	}
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (0);
	while (idx < s_len)
	{
		temp[idx] = s[idx];
		if (s[idx++] == '\n')
		{
			temp[idx] = '\0';
			while (idx <= s_len)
				*(line++) = s[idx++];
			*ret = ft_strjoin(*ret, temp);
			return (0);
		}
	}
	s[0] = '\0';
	temp[s_len] = '\0';
	*ret = ft_strjoin(*ret, temp);
	if (*ret == NULL)
		return (0);
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
	if (line[0] != '\0' && parse_buffer(line, &ret, line) == 0)
		return (ret);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0)
	{
		free(ret);
		return (NULL);
	}
	buffer[size] = '\0';
	if (parse_buffer(buffer, &ret, line) == 0)
		return (ret);
	ret = ft_strjoin(ret, get_next_line(fd));
	return (ret);
}


