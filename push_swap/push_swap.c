/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:24 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/30 22:09:24 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char *argv[])
{
	t_deque stack_a;
	t_deque	stack_b;

	//atexit(print_error);
	if (argc <= 1)
		exit(EXIT_FAILURE);
	dq_init(&stack_a);
	dq_init(&stack_b);
	init(&stack_a, &stack_b, argv);
	if (stack_a.size <= 5)
		push_swap_small(&stack_a, &stack_b);
	else
		push_swap(&stack_a, &stack_b);
	// free(stack_a);
	// free(stack_b);
	// return (0);
}

void	init(t_deque *stack_a, t_deque *stack_b, char *argv[])
{
	stack_b = NULL;
	parse_input(argv, stack_a);
	check_input(stack_a);
	order_index(stack_a);
}

void check_input(t_deque *stack_a)
{
	t_node	*cur;
	t_node	*temp;
	size_t	idx;

	cur = stack_a -> head;
	idx = 0;
	while (idx < stack_a -> size)
	{
		temp = cur -> next;
		while (temp)
		{
			if (cur -> data == temp -> data)
				exit(EXIT_FAILURE);
			temp = temp -> next;
		}
		idx++;
		cur = cur -> next;
	}
}

void	order_index(t_deque *stack_a)
{
	t_node	*cur;
	int		*arr;
	int		idx;

	idx = 0;
	arr = (int *)malloc(sizeof(int) * stack_a->size);
	if (arr == NULL)
		exit(EXIT_FAILURE);
	get_index(stack_a, arr);
	cur = stack_a -> head;
	while (cur)
	{
		cur ->data = arr[idx++];
		cur = cur->next;
	}
	free(arr);
}

void	get_index(t_deque *stack_a, int *arr)
{
	t_node	*cur;
	t_node	*temp;
	size_t	idx;

	cur = stack_a -> head;
	idx = -1;
	while (++idx < stack_a -> size)
	{
		temp = stack_a -> head;
		arr[idx] = 0;
		while (temp)
		{
			if (cur -> data > temp -> data)
				arr[idx]++;
			temp = temp -> next;
		}
		cur = cur -> next;
	}
}

void	push_swap(t_deque *stack_a, t_deque *stack_b)
{
	const int	pivot_low = stack_a -> size / 3;
	const int	pivot_high = stack_a -> size * 2 / 3;
	const int	is_sorted = dq_is_sorted(stack_a);

	if (is_sorted == 1)
		exit(EXIT_SUCCESS);
	else if (is_sorted == 0)
	{
		rotate_stack(stack_a, 0);
		exit(EXIT_SUCCESS);
	}
	divide_stack(stack_a, stack_b, pivot_low, pivot_high);
	printf("%zu, %zu\n",stack_a->size,stack_b->size);
	dq_print_data(stack_a);
	dq_print_data(stack_b);
	//greedy(stack_a, stack_b);
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
			ra_op(stack_a);
		else if (top < low)
		{
			pb_op(stack_a, stack_b);
			rb_op(stack_b);
		}
		else
			pb_op(stack_a, stack_b);
		idx ++;
	}
	cur = stack_a -> head;
	while (stack_a -> size > 3)
		pb_op(stack_a, stack_b);
	push_swap_three(stack_a, stack_b);
}

// void	greedy(t_deque *stack_a, t_deque *stack_b)
// {
// 	const size_t	b_size = stack_b -> size;
// 	int				to_move_idx;

// 	while (!dq_is_empty(stack_b))
// 	{
// 		to_move_idx = calc_op_num();
// 		rotate_stack(stack_b, to_move_idx);//idx 가  아니라 데이터를 넘겨야 함
// 		rotate_stack(stack_a, )	//넣어 주어야 할 자리로 돌리기
// 		pa_op(stack_a, stack_b);	//넘기기
// 	}
// }
