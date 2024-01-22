/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:16:34 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/14 21:09:43 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	lst_add_back(t_list **head, t_list *new)
{
	t_list	*temp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
	return ;
}

t_list	*init_list(int fd)
{
	t_list			*cur;
	t_list			*new;
	static t_list	*head;

	if (fd < 0)
		return (MALLOC_ERROR);
	if (head != NULL)
	{
		cur = head;
		while (cur != NULL)
		{
			if (cur->fd == fd)
				return (cur);
			cur = cur -> next;
		}
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (new == MALLOC_ERROR)
		return (MALLOC_ERROR);
	new -> line[0] = '\0';
	new -> next = NULL;
	new -> fd = fd;
	new -> malloc_size = 8;
	lst_add_back(&head, new);
	return (new);
}

int	parse_buffer(char *read_buf, char *ret_buf, char *prev_buf, int *malloc_size)
{
	const int	read_buf_len = ft_strlen(read_buf);
	const int	ret_buf_len = ft_strlen(ret_buf);
	const int	parse_idx = ft_strchr(read_buf, '\n');

	while (ret_buf_len + parse_idx + 1 > *malloc_size)
	{
		ret_buf = realloc(ret_buf, *malloc_size * 2);
		if (ret_buf == MALLOC_ERROR)
			return (MALLOC_ERROR);
		*malloc_size *= 2;
	}
	paste(ret_buf, read_buf, 0, parse_idx);
	if (parse_idx < read_buf_len)
	{
		paste(prev_buf, read_buf, parse_idx + 1, read_buf_len);
		return (RET_BUF_COMPLETE);
	}
	return (-1);
}

int	paste(char *dst, char *src, size_t start, size_t end)
{
	const size_t	dst_len = ft_strlen(dst);
	size_t			idx;

	idx = 0;
	while (idx <= end - start)
	{
		(dst)[dst_len + idx] = src[start + idx];
		idx++;
	}
	(dst)[dst_len + idx] = '\0';
	return (0);
}

int	init_buffer(char **ret_buf, char *prev_buf, int *malloc_size)
{
	int	len;
	int	temp;

	len = 0;
	*ret_buf = (char *)malloc(INIT_LINE_SIZE);
	if (*ret_buf == MALLOC_ERROR)
		return (MALLOC_ERROR);
	**ret_buf = '\0';
	temp = parse_buffer(prev_buf, *ret_buf, prev_buf, malloc_size);
	if (temp == MALLOC_ERROR)
	{
		free(*ret_buf);
		return (MALLOC_ERROR);
	}
	else if (temp == RET_BUF_COMPLETE)
		return (RET_BUF_COMPLETE);
	len = ft_strlen(prev_buf);
	paste(*ret_buf, prev_buf, 0, len);
	return (-1);
}

char	*get_next_line(int fd)
{
	char			*ret_buf = 0;
	int				size;
	char			read_buf[BUFFER_SIZE + 1];
	int				temp;
	t_list			*node;

	node = init_list(fd);
	if (node == MALLOC_ERROR)
		return (NULL);
	temp = init_buffer(&ret_buf, node -> line, &node -> malloc_size);
	if (temp == MALLOC_ERROR)
		return (NULL);
	else if (temp == RET_BUF_COMPLETE)
		return ((ret_buf));
	size = read(fd, read_buf, BUFFER_SIZE);
	while ((size) > 0)
	{
		read_buf[size] = '\0';
		temp = parse_buffer(read_buf, ret_buf, node -> line, &(node ->malloc_size));
		if (temp == MALLOC_ERROR)
			return (NULL);
		else if (temp == 1)
			return ((ret_buf));
		if (size < BUFFER_SIZE)
			break ;
		size = read(fd, read_buf, BUFFER_SIZE);
	}
	return ((ret_buf));
}

int	main()
{
	int	fd;

	fd = open( "./input.txt",O_RDWR);
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
	close(fd);
}
