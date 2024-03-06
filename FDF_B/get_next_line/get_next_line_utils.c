/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:35:48 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/06 16:10:35 by sehwjang         ###   ########.fr       */
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
