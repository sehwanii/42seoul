/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:24 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/26 14:26:52 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	int		*input;

	if (argc <= 1)
	{
		write(2, "ERROR\n", 6);
		return (EXIT_FAILURE);
	}
	atexit(free_stack(stack_a, stack_b));
	init(stack_a, stack_b, input);
	//dq_print_data(stack_a);
	if (stack_a -> size <= 5)
		push_swap_small(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

void	init(t_deque *stack_a, t_deque *stack_b, char *argv[])
{
	stack_a = NULL;
	stack_b = NULL;
	parse_input(argv, stack_a);
	//order_index()
}


int	push_swap(t_deque *stack_a, t_deque *stack_b)
{
	const int	pivot_low = stack_a -> size / 3;
	const int	pivot_high = stack_a -> size / 3 * 2;

	if (dq_is_sorted(stack_a))
		exit(EXIT_SUCCESS);
}
