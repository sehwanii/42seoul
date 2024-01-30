/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/30 22:03:43 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			dq_add_last(stack_a, ft_atoi(*temp));
			temp++;
		}
		argv++;
	}
	return ;
}

void	ft_write(int fd, char *str)
{
	if (write(fd, str, ft_strlen(str)) == -1)
		exit(EXIT_FAILURE);
}

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

void	rotate_stack(t_deque *stack_a, t_data data)
{
	t_node	*cur;
	size_t	idx;

	idx = 0;
	cur = stack_a -> head;
	while (cur)
	{
		if (cur -> data == data)
			break ;
		idx++;
		cur = cur -> next;
	}
	if (idx <= stack_a -> size / 2)
	{
		while (dq_get_first(stack_a) != data)
			ra_op(stack_a);
	}
	else
	{
		while (dq_get_first(stack_a) != data)
			rra_op(stack_a);
	}
}

void	print_error(void)
{
	write(2, "ERROR", 5);
}
