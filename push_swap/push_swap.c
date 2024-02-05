/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:24 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 20:16:37 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_deque *stack_a, t_deque *stack_b)
{
	const int	pivot_low = stack_a -> size / 3;
	const int	pivot_high = stack_a -> size * 2 / 3;
	const int	is_sorted = dq_is_sorted(stack_a);

	if (is_sorted == 1)
		exit(EXIT_SUCCESS);
	else if (is_sorted == 0)
	{
		rotate_stack(stack_a, 0, 0);
		exit(EXIT_SUCCESS);
	}
	divide_stack(stack_a, stack_b, pivot_low, pivot_high);
	greedy(stack_a, stack_b);
}

void	divide_stack(t_deque *stack_a, t_deque *stack_b, int low, int high)
{
	t_node			*cur;
	size_t			idx;
	const size_t	a_size = stack_a -> size;
	int				top;

	idx = 0;
	while (idx < a_size)
	{
		top = dq_get_first(stack_a);
		if (top >= high)
			ra_op(stack_a, 0);
		else if (top < low)
		{
			pb_op(stack_a, stack_b, 0);
			rb_op(stack_b, 0);
		}
		else
			pb_op(stack_a, stack_b, 0);
		idx ++;
	}
	cur = stack_a -> head;
	while (stack_a -> size > 3)
		pb_op(stack_a, stack_b, 0);
	push_swap_three(stack_a, stack_b);
}

void	greedy(t_deque *stack_a, t_deque *stack_b)
{
	int				to_move_data;
	int				rotate;
	int				idx;

	while (!dq_is_empty(stack_b))
	{
		idx = -1;
		to_move_data = calc_op_num(stack_a, stack_b);
		rotate_stack(stack_b, 1, to_move_data);
		rotate = find_place(stack_a, to_move_data);
		if (rotate > 0)
		{
			while (++idx < rotate)
				ra_op(stack_a, 0);
		}
		else
		{
			while (++idx < rotate * -1)
				rra_op(stack_a, 0);
		}
		pa_op(stack_a, stack_b, 0);
	}
	rotate_stack(stack_a, 0, 0);
}
