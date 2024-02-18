/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:35:48 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/06 13:17:47 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*gnl_lstnew(int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
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

void	gnl_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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
