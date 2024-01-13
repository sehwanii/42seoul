/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:16:34 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/13 21:06:43 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	paste(char **dst, char *src, size_t start, size_t end)
{
	const size_t	dst_len = ft_strlen(*dst);
	size_t			idx;

	idx = 0;
	while (idx <= end - start)
	{
		(*dst)[dst_len + idx] = src[start + idx];
		idx++;
	}
	(*dst)[dst_len + idx] = '\0';
	return (0);
}

int	parse_buffer(char *read_buf, char **ret_buf, char **prev_buf, int *malloc_size)
{
	const int	read_buf_len = ft_strlen(read_buf);
	const int	ret_buf_len = ft_strlen(*ret_buf);
	const int	parse_idx = ft_strchr(read_buf, '\n');

	while (ret_buf_len + read_buf_len + 1 > *malloc_size)
	{
		*ret_buf = realloc(*ret_buf, *malloc_size * 2);
		*malloc_size *= 2;
		if (*ret_buf == NULL)
			return (-1);
	}
	if (paste(ret_buf, read_buf, 0, parse_idx) == -1)
		return (-1);
	if (parse_idx < read_buf_len)
	{
		free(*prev_buf);
		*prev_buf = (char *)malloc(read_buf_len - parse_idx);
		if (paste(prev_buf, read_buf, parse_idx + 1, read_buf_len) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	init_buffer(char **ret_buf, char **prev_buf, int *malloc_size)
{
	int	len;
	int	temp;

	len = 0;
	if (*prev_buf == NULL || **prev_buf == '\0')
	{
		*ret_buf = (char *)malloc(10);
		ret_buf = NULL;
	}
	else
	{
		*ret_buf = (char *)malloc(10);
		temp = parse_buffer(*prev_buf, ret_buf, prev_buf, malloc_size);
		if (temp == -1)
			return (-1);
		else if (temp == 1)
			return (1);
		len = ft_strlen(*prev_buf);
		if (paste(ret_buf, *prev_buf, 0, len) == -1)
			return (-1);
	}
	return (0);
}

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
	t_list	*cur;
	t_list	*new;
	static t_list	*head;
	
	if (head != NULL)
	{
		cur = head;
		while (cur != NULL)
		{
			if (cur->fd == fd)
				return (cur);
		}
	}	
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new -> line = (char *)malloc(10);
	if (new -> line == NULL)
		return (0);
	new -> next = NULL;
	new -> fd = fd;
	new -> malloc_size = 10;
	lst_add_back(&head, new);
	return (new);
}

char	*get_next_line(int fd)
{
	char			*ret_buf;
	int				size;
	char			read_buf[BUFFER_SIZE + 1];
	int				temp;
	t_list			*node;

	node = init_list(fd);
	if (node == NULL)
		return (NULL);
	temp = init_buffer(&ret_buf, &node -> line, &node -> malloc_size);
	if (temp == -1)
		return (NULL);
	else if (temp == 1)
		return (ft_realloc(ret_buf));
	size = read(fd, read_buf, BUFFER_SIZE);
	while ((size) > 0)
	{
		read_buf[size] = '\0';
		temp = parse_buffer(read_buf, &ret_buf, &(node -> line), &(node ->malloc_size));
		if (temp == -1)
			return (NULL);
		else if (temp == 1)
			return (ft_realloc(ret_buf));
		if (size < BUFFER_SIZE)
			break ;
		size = read(fd, read_buf, BUFFER_SIZE);
	}
	return (ft_realloc(ret_buf));
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
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
