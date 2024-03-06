/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:22:36 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 21:05:24 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_op(t_deque *stack_a, int bonus)
{
	if (bonus == 0)
		ft_write(1, "sa\n");
	s_op(stack_a);
	return ;
}

void	sb_op(t_deque *stack_b, int bonus)
{
	if (bonus == 0)
		ft_write(1, "sb\n");
	s_op(stack_b);
	return ;
}

void	s_op(t_deque *stack)
{
	t_data	first;
	t_data	second;

	if (dq_is_empty(stack))
		return ;
	first = dq_pop_first(stack);
	if (dq_is_empty(stack))
	{
		dq_add_first(stack, first);
		return ;
	}
	second = dq_pop_first(stack);
	dq_add_first(stack, first);
	dq_add_first(stack, second);
	return ;
}

void	ss_op(t_deque *stack_a, t_deque *stack_b, int bonus)
{
	if (bonus == 0)
		ft_write(1, "ss\n");
	s_op(stack_a);
	s_op(stack_b);
	return ;
}
