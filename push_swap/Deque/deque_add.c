/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:30:36 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 19:52:39 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	dq_add_first(t_deque *pdeq, t_data data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (MALLOC_ERROR);
	new -> data = data;
	new -> next = pdeq -> head;
	if (dq_is_empty(pdeq))
		pdeq -> tail = new;
	else
		pdeq -> head -> prev = new;
	new -> prev = NULL;
	pdeq -> head = new;
	pdeq -> size++;
	return (SUCCESS);
}

int	dq_add_last(t_deque *pdeq, t_data data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (MALLOC_ERROR);
	new -> data = data;
	new -> prev = pdeq -> tail;
	if (dq_is_empty(pdeq))
		pdeq -> head = new;
	else
		pdeq -> tail -> next = new;
	new -> next = NULL;
	pdeq -> tail = new;
	pdeq -> size++;
	return (SUCCESS);
}
