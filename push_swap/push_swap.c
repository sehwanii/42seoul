/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:24 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/24 16:55:37 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	//t_list	*stack_a;
	//t_list	*stack_b;
	int		*input;

	if (argc <= 1)
	{
		write(2, "ERROR\n", 6);
		return (EXIT_FAILURE);
	}
	//atexit(free_stack());
	input = parse_input(argv);
	for(int i = 0; i< 10; i++)
		printf("%d ",input[i]);
	//init_stack(stack_a, stack_b, parse_input(argv));
	//push_swap();

}

// int	push_swap(t_list *stack_a, t_list *stack_b, int arr[])
// {
	
// }
