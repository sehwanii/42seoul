/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:49:46 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 20:17:19 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_small(t_deque *stack_a, t_deque *stack_b)
{
	if (stack_a -> size == 1)
		exit(EXIT_SUCCESS);
	else if (stack_a -> size == 2)
		push_swap_two(stack_a);
	else if (stack_a -> size == 3)
		push_swap_three(stack_a, stack_b);
	else if (stack_a -> size == 4)
		push_swap_four(stack_a, stack_b);
	else
		push_swap_five(stack_a, stack_b);
	exit(EXIT_SUCCESS);
}

void	push_swap_two(t_deque *stack_a)
{
	if (dq_is_sorted(stack_a) == 1)
		return ;
	else
	{
		ra_op(stack_a, 0);
		return ;
	}
}

void	push_swap_three(t_deque *stack_a, t_deque *stack_b)
{
	int		is_sorted;
	t_data	min_data;
	t_data	max_data;

	is_sorted = dq_is_sorted(stack_a);
	min_data = dq_get_min_data(stack_a);
	max_data = dq_get_max_data(stack_a);
	if (is_sorted == 1)
		return ;
	else if (is_sorted == 0)
		rotate_stack(stack_a, 0, min_data);
	else if (dq_get_first(stack_a) == min_data)
	{
		pb_op(stack_a, stack_b, 0);
		ra_op(stack_a, 0);
		pa_op(stack_a, stack_b, 0);
	}
	else if (dq_get_first(stack_a) == max_data)
	{
		sa_op(stack_a, 0);
		rra_op(stack_a, 0);
	}
	else
		sa_op(stack_a, 0);
}

void	push_swap_four(t_deque *stack_a, t_deque *stack_b)
{
	int	is_sorted;

	is_sorted = dq_is_sorted(stack_a);
	if (is_sorted == 1)
		return ;
	else if (is_sorted == 0)
	{
		rotate_stack(stack_a, 0, 0);
		return ;
	}
	if (dq_get_last(stack_a) == 3)
		rra_op(stack_a, 0);
	else
	{
		while (dq_get_first(stack_a) != 3)
			ra_op(stack_a, 0);
	}
	pb_op(stack_a, stack_b, 0);
	push_swap_three(stack_a, stack_b);
	pa_op(stack_a, stack_b, 0);
	ra_op(stack_a, 0);
}

void	push_swap_five(t_deque *stack_a, t_deque *stack_b)
{
	int	is_sorted;

	is_sorted = dq_is_sorted(stack_a);
	if (is_sorted == 1)
		return ;
	else if (is_sorted == 0)
		rotate_stack(stack_a, 0, 0);
	if (dq_get_last(stack_a) == 4)
		rra_op(stack_a, 0);
	else
	{
		while (dq_get_first(stack_a) != 4)
			ra_op(stack_a, 0);
	}
	pb_op(stack_a, stack_b, 0);
	push_swap_four(stack_a, stack_b);
	pa_op(stack_a, stack_b, 0);
	ra_op(stack_a, 0);
}
