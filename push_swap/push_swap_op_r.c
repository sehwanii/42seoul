/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:37:47 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/25 01:37:49 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_op(t_deque *stack_a)
{
	ft_write(1, "ra\n");
	r_op(stack_a);
	return ;
}

void	rb_op(t_deque *stack_b)
{
	ft_write(1, "rb\n");
	r_op(stack_b);
	return ;
}

void	r_op(t_deque *stack)
{
	if (dq_is_empty(stack))
		return ;
	dq_add_last(stack, dq_pop_first(stack));
	return ;
}

void	rra_op(t_deque *stack_a)
{
	ft_write(1, "rra\n");
	rev_r_op(stack_a);
	return ;
}

void	rrb_op(t_deque *stack_b)
{
	ft_write(1, "rrb\n");
	rev_r_op(stack_b);
	return ;
}
