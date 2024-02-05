/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:45:20 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 19:45:38 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	stack_a;
	t_deque	stack_b;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	dq_init(&stack_a);
	dq_init(&stack_b);
	init(&stack_a, &stack_b, argv);
	if (stack_a.size <= 5)
		push_swap_small(&stack_a, &stack_b);
	else
		push_swap(&stack_a, &stack_b);
	exit(EXIT_SUCCESS);
}
