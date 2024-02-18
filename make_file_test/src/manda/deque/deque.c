/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:11:22 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/06 14:28:30 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
//#include "ft_printf.h"

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

void	dq_clear(t_deque *pdeq)
{
	while (!dq_is_empty(pdeq))
		dq_pop_first(pdeq);
	free(pdeq);
}
// void	dq_print_data(t_deque *pdeq)
// {
// 	t_node	*cur;
// 	size_t	idx;

// 	cur = pdeq -> head;
// 	while (idx < pdeq -> size)
// 	{
// 		ft_printf("%d : %d ", idx, cur -> data);
// 		cur = cur -> next;
// 	}
// }
