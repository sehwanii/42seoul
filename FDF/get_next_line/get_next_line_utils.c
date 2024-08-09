/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:35:48 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/31 16:53:59 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*gnl_lstnew(int fd)
{
	t_gnl_list	*node;

	node = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (node == NULL)
		return (0);
	node -> fd = fd;
	node -> line = (char *)malloc(BUFFER_SIZE + 1);
	if (node -> line == NULL)
	{
		free(node);
		return (0);
	}
	node -> line[0] = '\0';
	node -> next = NULL;
	return (node);
}

void	gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new)
{
	t_gnl_list	*temp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
}

void	free_node(t_gnl_list **head, int fd)
{
	t_gnl_list	*cur;
	t_gnl_list	*next;

	cur = *head;
	if (cur -> fd == fd)
	{
		next = cur -> next;
		free(cur -> line);
		free(cur);
		*head = next;
		return ;
	}
	while (cur -> next)
	{
		if (cur -> next -> fd == fd)
		{
			next = cur -> next -> next;
			free(cur -> next -> line);
			free(cur -> next);
			cur -> next = next;
			return ;
		}
		cur = cur -> next;
	}
}

char	*gnl_strjoin(char *s1, char *s2)
{
	const size_t	prefix_len = gnl_strlen(s1);
	const size_t	suffix_len = gnl_strlen(s2);
	const size_t	total_len = prefix_len + suffix_len;
	char			*ret_str;
	size_t			idx;

	idx = -1;
	ret_str = (char *)malloc(total_len + 1);
	if (ret_str == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (++idx < prefix_len)
		ret_str[idx] = s1[idx];
	idx = -1;
	while (++idx < suffix_len)
		ret_str[prefix_len + idx] = s2[idx];
	ret_str[total_len] = '\0';
	free(s1);
	free(s2);
	return (ret_str);
}

size_t	gnl_strlen(const char *s)
{
	size_t	cnt;

	if (s == NULL)
		return (0);
	cnt = 0;
	while ((s[cnt]))
		cnt++;
	return (cnt);
}
