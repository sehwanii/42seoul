/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:11:22 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/25 00:48:00 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dq_init(t_deque *pdeq)
{
	pdeq -> head = NULL;
	pdeq -> tail = NULL;
	pdeq -> size = 0;
}

int	dq_is_empty(t_deque *pdeq)
{
	if (pdeq -> head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

int	dq_is_sorted(t_deque *pdeq)
{
	t_node	*cur;
	size_t	idx;

	cur = pdeq -> head;
	idx = 0;
	while (idx < pdeq -> size)
	{
		if (cur -> data > cur -> next -> data)
			return (FALSE);
		idx ++;
		cur = cur -> next;
	}
	return (TRUE);
}

#include <stdio.h>

void	dq_print_data(t_deque *pdeq)
{
	t_node	*cur;
	size_t	idx;

	cur = pdeq -> head;
	idx = 0;
	while (idx < pdeq -> size)
	{
		printf("%zu : %d ", idx, cur -> data);
		idx++;
		cur = cur -> next;
	}
}
