/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:15:59 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/28 23:49:07 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
int main()
{
	int fd = open("input.txt", O_RDONLY);

    if (fd == -1) {

        exit(EXIT_FAILURE);
    }

    // 여기서 파일 디스크립터(fd)를 사용하여 다양한 파일 작업을 수행할 수 있습니다.
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
    // 파일 닫기
    close(fd);
}

int	split_word(char *s, char **ret, char *line)
{
	const size_t	s_len = ft_strlen(s);
	size_t			idx;
	char			*temp;

	idx = 0;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (MALLOC_ERROR);
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
	return (1);
}

int	parse_buffer(char *s, char **ret, char *line, int *flag)
{
	if (*ret == NULL)
	{
		*ret = (char *)malloc(BUFFER_SIZE + 1);
		if (*ret == NULL)
		{
			*flag = MALLOC_ERROR;
			return (0);
		}
		**ret = '\0';
	}
	if (split_word(s, ret, line) == MALLOC_ERROR)
	{
		*flag = MALLOC_ERROR;
		return (MALLOC_ERROR);
	}
	else
	{
		if (*ret == NULL)
			return (0);
		return (1);
	}
	if (*ret == NULL)
		return (0);
	return (1);
}

char	*get_next_line(int fd, char **line, int *flag)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			size;

	if (*flag == MALLOC_ERROR || fd < 0)
		return (NULL);
	ret = NULL;
	if (parse_buffer(*line, &ret, *line, flag) == 0)
		return (ret);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0)
		return (ret);
	if (size == -1)
	{
		(*line)[0] = '\0';
		free(ret);
		return (NULL);
	}
	buffer[size] = '\0';
	if (parse_buffer(buffer, &ret, *line, flag) == 0)
		return (ret);
	ret = ft_strjoin(ret, get_next_line(fd, line, flag));
	return (ret);
}

char	*gnl(int fd)
{
	static t_list	*head;
	t_list			*node;
	int				flag;

	if (fd < 0)
		return (NULL);
	flag = MALLOC_OK;
	if (find_node(&head, &node, fd) == MALLOC_ERROR)
		return (NULL);
	return (get_next_line(fd, &(node -> line), &flag));
}

int	find_node(t_list **head, t_list **node, int fd)
{
	t_list	*cur;
	t_list	*new;

	cur = *head;
	if (cur != NULL)
	{
		while (cur -> next)
		{
			if (cur -> fd == fd)
			{
				*node = cur;
				return (MALLOC_OK);
			}
			cur = cur -> next;
		}
	}
	cur = ft_lstnew(fd);
	if (cur == NULL)
		return (MALLOC_ERROR);
	ft_lstadd_back(head, cur);
	*node = cur;
	return (MALLOC_OK);
}
