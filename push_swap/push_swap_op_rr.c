/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:37:32 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 20:59:29 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_r_op(t_deque *stack)
{
	if (dq_is_empty(stack))
		return ;
	dq_add_first(stack, dq_pop_last(stack));
	return ;
}

void	rr_op(t_deque *stack_a, t_deque *stack_b, int bonus)
{
	if (bonus == 0)
		ft_write(1, "rr\n");
	r_op(stack_a);
	r_op(stack_b);
	return ;
}

void	rev_rr_op(t_deque *stack_a, t_deque *stack_b, int bonus)
{
	if (bonus == 0)
		ft_write(1, "rrr\n");
	rev_r_op(stack_a);
	rev_r_op(stack_b);
	return ;
}
