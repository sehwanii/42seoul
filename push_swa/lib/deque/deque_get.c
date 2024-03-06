/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:42:53 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 19:54:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_data	dq_get_first(t_deque *pdeq)
{
	if (dq_is_empty(pdeq))
		exit(EXIT_FAILURE);
	return (pdeq -> head -> data);
}

t_data	dq_get_last(t_deque *pdeq)
{
	if (dq_is_empty(pdeq))
		exit(EXIT_FAILURE);
	return (pdeq -> tail -> data);
}

t_data	dq_get_min_data(t_deque *pdeq)
{
	t_node	*cur;
	t_data	min_data;

	cur = pdeq -> head;
	min_data = cur -> data;
	cur = cur -> next;
	while (cur)
	{
		if (cur -> data < min_data)
			min_data = cur -> data;
		cur = cur -> next;
	}
	return (min_data);
}

t_data	dq_get_max_data(t_deque *pdeq)
{
	t_node	*cur;
	t_data	max_data;

	cur = pdeq -> head;
	max_data = cur -> data;
	cur = cur -> next;
	while (cur)
	{
		if (cur -> data > max_data)
			max_data = cur -> data;
		cur = cur -> next;
	}
	return (max_data);
}
