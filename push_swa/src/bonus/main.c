/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:36:26 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 23:12:50 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_leak(void)
{
	system("leaks checker");
}

int	main(int argc, char *argv[])
{
	t_deque	stack_a;
	t_deque	stack_b;

	atexit(check_leak);
	if (argc <= 1)
		exit(0);
	dq_init(&stack_a);
	dq_init(&stack_b);
	init(&stack_a, argv);
	checker(&stack_a, &stack_b);
}
