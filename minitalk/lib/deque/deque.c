/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:11:22 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 20:26:07 by sehwjang         ###   ########.fr       */
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
	int		flag;

	flag = 1;
	cur = pdeq -> head;
	idx = 0;
	while (idx < pdeq -> size - 1)
	{
		if (cur -> data >= cur -> next -> data)
			flag --;
		idx ++;
		cur = cur -> next;
	}
	if (flag == 1)
		return (1);
	if (dq_get_first(pdeq) < dq_get_last(pdeq))
		flag --;
	return (flag);
}

int	dq_find_index(t_deque *pdeq, t_data data)
{
	t_node	*cur;
	size_t	idx;

	cur = pdeq -> head;
	idx = 0;
	while (idx < pdeq -> size)
	{
		if (cur -> data == data)
			return (idx);
		idx++;
		cur = cur -> next;
	}
	return (-1);
}

void	dq_free(t_deque *pdeq)
{
	while (!dq_is_empty(pdeq))
		dq_pop_last(pdeq);
}

// #include <stdio.h>

// void	dq_print_data(t_deque *pdeq)
// {
// 	t_node	*cur;
// 	size_t	idx;

// 	cur = pdeq -> head;
// 	idx = 0;
// 	while (idx < pdeq -> size)
// 	{
// 		printf("%zu : %d\n", idx, cur -> data);
// 		idx++;
// 		cur = cur -> next;
// 	}
// }
