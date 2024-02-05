/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:30:07 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 19:55:31 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_deque *stack_a, t_deque *stack_b, char *argv[])
{
	stack_b = NULL;
	parse_input(argv, stack_a);
	check_input(stack_a);
	order_index(stack_a);
}

void	parse_input(char *argv[], t_deque *stack_a)
{
	int		idx;
	char	**temp;

	idx = 0;
	argv++;
	while (*argv != NULL)
	{
		temp = ft_split(*argv, ' ');
		while (*temp != NULL)
		{
			if (dq_add_last(stack_a, ft_atoi(*temp)) == MALLOC_ERROR)
			{
				ft_write(2, "ERROR\n");
				exit(EXIT_FAILURE);
			}
			temp++;
		}
		argv++;
	}
	return ;
}

void	check_input(t_deque *stack_a)
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
			{
				ft_write(2, "ERROR\n");
				exit(EXIT_FAILURE);
			}
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
	{
		ft_write(2, "ERROR\n");
		exit(EXIT_FAILURE);
	}
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
