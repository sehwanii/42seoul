/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:49:46 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/25 01:39:18 by sehwjang         ###   ########.fr       */
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
		push_swap_three(stack_a);
	else if (stack_a -> size == 4)
		push_swap_four(stack_a, stack_b);
	else
		push_swap_five(stack_a, stack_b);
}

void	push_swap_two(t_deque *stack_a)
{
	if (dq_is_sorted(stack_a))
		return ;
	else
	{
		ft_write(1, "ra\n");
		return ;
	}
}

void	push_swap_three(t_deque *stack_a)
{
	if (dq_get_last(stack_a) == 2)
	{
		dq_pop_last(stack_a);
		push_swap_two(stack_a);
	}
	else if (dq_get_first(stack_a) == 2)
	{
		ra(stack_a);
		dq_pop_last(stack_a);
		push_swap_two(stack_a);
	}
	else if (dq_get_first(stack_a) == 1)
	{
		dq_pop_first(stack_a);
		ft_write(1, "rra\n");
	}
	else
	{
		ft_write(1, "pa\n");
		ft_write(1, "ra\n");
	}
}

void	push_swap_four(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*cur;

	cur = stack_a -> head;
	if (dq_get_first(stack_a) == 3)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		push_swap_three(stack_a);
		ft_write(1, "pa\n");
		ft_write(1, "ra\n");
	}
	else
	{
		while (cur -> data != 3)
		{
			cur = cur -> next;
			sa(stack_a);
		}
		pb(stack_a, stack_b);
		push_swap_three(stack_a);
		ft_write(1, "pa\n");
		ft_write(1, "ra\n");
	}
}

void	push_swap_five(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*cur;

	cur = stack_a -> head;
	if (dq_get_first(stack_a) == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		push_swap_three(stack_a);
		ft_write(1, "pa\n");
		ft_write(1, "ra\n");
	}
	else
	{
		while (cur -> data != 4)
		{
			cur = cur -> next;
			sa(stack_a);
		}
		pb(stack_a, stack_b);
		push_swap_four(stack_a, stack_b);
		ft_write(1, "pa\n");
		ft_write(1, "ra\n");
	}
}

