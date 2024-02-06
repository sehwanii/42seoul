/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:21:43 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 21:28:51 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(const char *error_msg);
static void	excute_op(t_deque *stack_a, t_deque *stack_b, char *op);

int	main(int argc, char *argv[])
{
	t_deque	stack_a;
	t_deque	stack_b;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	dq_init(&stack_a);
	dq_init(&stack_b);
	init(&stack_a, &stack_b, argv);
	checker(&stack_a, &stack_b);
}

void	checker(t_deque *stack_a, t_deque *stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		excute_op(stack_a, stack_b, op);
		free(op);
		op = get_next_line(0);
	}
	if (dq_is_sorted(stack_a))
	{
		ft_write(1, "OK\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_write(2, "KO\n");
		exit(EXIT_FAILURE);
	}
}

static void	excute_op(t_deque *stack_a, t_deque *stack_b, char *op)
{
	if (ft_strncmp("rrr", op, 3))
		rev_rr_op(stack_a, stack_b, 1);
	else if (ft_strncmp("rra", op, 3))
		rra_op(stack_a, 1);
	else if (ft_strncmp("rrb", op, 3))
		rrb_op(stack_a, 1);
	else if (ft_strncmp("ra", op, 2))
		ra_op(stack_a, 1);
	else if (ft_strncmp("rb", op, 2))
		rb_op(stack_a, 1);
	else if (ft_strncmp("rr", op, 2))
		rr_op(stack_a, stack_b, 1);
	else if (ft_strncmp("pa", op, 2))
		pa_op(stack_a, stack_b, 1);
	else if (ft_strncmp("pb", op, 2))
		pb_op(stack_a, stack_b, 1);
	else if (ft_strncmp("sa", op, 2))
		sa_op(stack_a, 1);
	else if (ft_strncmp("sb", op, 2))
		sb_op(stack_b, 1);
	else if (ft_strncmp("ss", op, 2))
		ss_op(stack_a, stack_b, 1);
	else
		print_error("ERROR\n");
}

static void	print_error(const char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}
