/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:21:43 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 23:58:04 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_error(const char *error_msg);
static void	excute_op(t_deque *stack_a, t_deque *stack_b, char *op);

void	checker(t_deque *stack_a, t_deque *stack_b)
{
	char	buf[5];
	t_list	*head;
	t_list	*cur;
	char	*temp;

	head = NULL;
	ft_memset(buf, 0, 5);
	while (read(0, buf, 4) > 0)
	{
		temp = ft_strdup(buf);
		ft_lstadd_back(&head, ft_lstnew(temp));
		ft_memset(buf, 0, 5);
	}
	cur = head;
	while (cur != NULL)
	{
		excute_op(stack_a, stack_b, cur->content);
		cur = cur -> next;
	}
	if (dq_is_sorted(stack_a) == 1 && dq_is_empty(stack_b))
		ft_write(1, "OK\n");
	else
		ft_write(1, "KO\n");
	exit(0);
}

static void	excute_op(t_deque *stack_a, t_deque *stack_b, char *op)
{
	if (!ft_strncmp("rrr", op, 3))
		rev_rr_op(stack_a, stack_b, 1);
	else if (!ft_strncmp("rra", op, 3))
		rra_op(stack_a, 1);
	else if (!ft_strncmp("rrb", op, 3))
		rrb_op(stack_a, 1);
	else if (!ft_strncmp("ra", op, 2))
		ra_op(stack_a, 1);
	else if (!ft_strncmp("rb", op, 2))
		rb_op(stack_a, 1);
	else if (!ft_strncmp("rr", op, 2))
		rr_op(stack_a, stack_b, 1);
	else if (!ft_strncmp("pa", op, 2))
		pa_op(stack_a, stack_b, 1);
	else if (!ft_strncmp("pb", op, 2))
		pb_op(stack_a, stack_b, 1);
	else if (!ft_strncmp("sa", op, 2))
		sa_op(stack_a, 1);
	else if (!ft_strncmp("sb", op, 2))
		sb_op(stack_b, 1);
	else if (!ft_strncmp("ss", op, 2))
		ss_op(stack_a, stack_b, 1);
	else
		print_error("ERROR\n");
}

static void	print_error(const char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}
