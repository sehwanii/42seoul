/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:34:17 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/30 03:42:23 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_op(t_deque *stack_a, t_deque *stack_b)
{
	t_data	data;

	ft_write(1, "pa\n");
	if (dq_is_empty(stack_b))
		return ;
	data = dq_pop_first(stack_b);
	dq_add_first(stack_a, data);
	return ;
}

void	pb_op(t_deque *stack_a, t_deque *stack_b)
{
	t_data	data;

	ft_write(1, "pb\n");
	if (dq_is_empty(stack_a))
		return ;
	data = dq_pop_first(stack_a);
	dq_add_first(stack_b, data);
	return ;
}

