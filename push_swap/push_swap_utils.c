/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 20:16:46 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*cur;
	t_node	*next;

	cur = stack_a -> head;
	while (cur != NULL)
	{
		next = cur -> next;
		free(cur);
		cur = next;
	}
	cur = stack_b -> head;
	while (cur != NULL)
	{
		next = cur -> next;
		free(cur);
		cur = next;
	}
	return ;
}

void	rotate_stack(t_deque *stack, int type, t_data data)
{
	t_node	*cur;
	size_t	idx;

	idx = 0;
	cur = stack -> head;
	while (cur)
	{
		if (cur -> data == data)
			break ;
		idx++;
		cur = cur -> next;
	}
	if (idx <= stack -> size / 2)
	{
		while (dq_get_first(stack) != data)
		{
			if (type == 0)
				ra_op(stack, 0);
			else
				rb_op(stack, 0);
		}
	}
	else
	{
		while (dq_get_first(stack) != data)
		{
			if (type == 0)
				rra_op(stack, 0);
			else
				rrb_op(stack, 0);
		}
	}
}

t_data	calc_op_num(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*cur;
	size_t	idx;
	int		min;
	int		temp;
	int		ret_data;

	min = MAX_INT;
	ret_data = stack_b -> head -> data;
	cur = stack_b -> head;
	idx = 0;
	while (idx < stack_b -> size)
	{
		temp = idx;
		if (idx > stack_b -> size / 2)
			temp = stack_b -> size - idx;
		temp += abs(find_place(stack_a, cur -> data));
		if (temp < min)
		{
			min = temp;
			ret_data = cur -> data;
		}
		idx++;
		cur = cur -> next;
	}
	return (ret_data);
}

int	find_place(t_deque *stack, t_data data)
{
	t_node	*cur;
	int		idx;
	t_data	prev;

	idx = 0;
	prev = dq_get_last(stack);
	if (dq_get_max_data(stack) < data)
		idx = dq_find_index(stack, dq_get_max_data(stack)) + 1;
	else if (dq_get_min_data(stack) > data)
		idx = dq_find_index(stack, dq_get_min_data(stack));
	else
	{
		cur = stack->head;
		while (idx < (int)(stack -> size))
		{
			if ((cur -> data > data && prev < data))
				break ;
			idx++;
			prev = cur -> data;
			cur = cur -> next;
		}
	}
	if (idx > (int)(stack -> size / 2))
		idx = ((int)(stack)->size - idx) * -1;
	return (idx);
}
