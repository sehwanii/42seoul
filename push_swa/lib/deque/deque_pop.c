/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:35:57 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 23:06:14 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_data	dq_pop_first(t_deque *pdeq)
{
	t_node	*r_node;
	t_data	r_data;

	r_node = pdeq -> head;
	if (dq_is_empty(pdeq))
		exit(EXIT_FAILURE);
	r_data = pdeq -> head -> data;
	pdeq -> head = pdeq -> head -> next;
	free(r_node);
	if (pdeq -> head == NULL)
		pdeq -> tail = NULL;
	else
		pdeq -> head -> prev = NULL;
	pdeq -> size--;
	return (r_data);
}

t_data	dq_pop_last(t_deque *pdeq)
{
	t_node	*r_node;
	t_data	r_data;

	r_node = pdeq -> tail;
	if (dq_is_empty(pdeq))
		exit(EXIT_FAILURE);
	r_data = pdeq -> tail -> data;
	pdeq -> tail = pdeq -> tail -> prev;
	free(r_node);
	if (pdeq -> tail == NULL)
		pdeq -> head = NULL;
	else
		pdeq -> tail -> next = NULL;
	pdeq -> size--;
	return (r_data);
}
