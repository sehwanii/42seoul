/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:07:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/31 18:15:33 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	split_word(char *s, char **ret, char *line)
{
	const size_t	s_len = gnl_strlen(s);
	size_t			idx;
	char			*temp;

	idx = 0;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (MALLOC_ERROR);
	while (idx <= s_len)
	{
		temp[idx] = s[idx];
		if (s[idx++] == '\n')
		{
			temp[idx] = '\0';
			while (idx <= s_len)
				*(line++) = s[idx++];
			*ret = gnl_strjoin(*ret, temp);
			return (PARSE_SUCCESS);
		}
	}
	s[0] = '\0';
	*ret = gnl_strjoin(*ret, temp);
	return (1);
}

int	parse_buffer(char *s, char **ret, char *line, int *flag)
{
	int	temp;

	if (*ret == NULL)
	{
		*ret = (char *)malloc(BUFFER_SIZE + 1);
		if (*ret == NULL)
		{
			*flag = MALLOC_ERROR;
			return (PARSE_SUCCESS);
		}
		**ret = '\0';
	}
	temp = split_word(s, ret, line);
	if (temp == MALLOC_ERROR || *ret == NULL)
		*flag = MALLOC_ERROR;
	else if (temp == PARSE_SUCCESS)
		return (PARSE_SUCCESS);
	return (1);
}

char	*gnl(int fd, char **line, int *flag)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			size;

	if (*flag == MALLOC_ERROR || fd < 0)
		return (NULL);
	if (*flag == READ_ALL && **line == '\0')
		*flag = RETURN_ALL;
	ret = NULL;
	if (parse_buffer(*line, &ret, *line, flag) == PARSE_SUCCESS)
		return (ret);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
	{
		free(ret);
		return (NULL);
	}
	buffer[size] = '\0';
	if (size == 0 || (*flag != MALLOC_ERROR && size < BUFFER_SIZE))
		*flag = READ_ALL;
	if (size == 0 || parse_buffer(buffer, &ret, *line, flag) == PARSE_SUCCESS)
		return (ret);
	ret = gnl_strjoin(ret, gnl(fd, line, flag));
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*node;
	int					flag;
	char				*ret;

	flag = MALLOC_OK;
	if (find_node(&head, &node, fd) == MALLOC_ERROR)
		return (NULL);
	ret = gnl(fd, &(node -> line), &flag);
	if (ret == NULL)
	{
		free_node(&head, fd);
		return (NULL);
	}
	if (flag == MALLOC_ERROR || *ret == '\0')
	{
		free(ret);
		free_node(&head, fd);
		return (NULL);
	}
	else if (flag == RETURN_ALL)
		free_node(&head, fd);
	return (ret);
}

int	find_node(t_gnl_list **head, t_gnl_list **node, int fd)
{
	t_gnl_list	*cur;

	cur = *head;
	if (cur != NULL)
	{
		while (cur)
		{
			if (cur -> fd == fd)
			{
				*node = cur;
				return (MALLOC_OK);
			}
			cur = cur -> next;
		}
	}
	cur = gnl_lstnew(fd);
	if (cur == NULL)
		return (MALLOC_ERROR);
	gnl_lstadd_back(head, cur);
	*node = cur;
	return (MALLOC_OK);
}
