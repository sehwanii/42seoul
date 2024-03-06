/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:42:53 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/25 00:03:04 by sehwjang         ###   ########.fr       */
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
