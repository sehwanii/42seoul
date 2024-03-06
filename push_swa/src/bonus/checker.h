/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:47 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 23:58:17 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../lib/libft/libft.h"
# include "../../lib/deque/deque.h"
# include "../../lib/my_utils/my_utils.h"

# define ERROR		-1
# define MAX_INT	2147483647

void	checker(t_deque *stack_a, t_deque *stack_b);

void	init(t_deque *stack_a, char *argv[]);
void	parse_input(char *argv[], t_deque *stack_a);
void	check_input(t_deque *stack_a);
void	order_index(t_deque *stack_a);
void	get_index(t_deque *stack_a, int *arr);

void	sa_op(t_deque *stack_a, int bonus);
void	sb_op(t_deque *stack_b, int bonus);
void	s_op(t_deque *stack);
void	ss_op(t_deque *stack_a, t_deque *stack_b, int bonus);

void	pa_op(t_deque *stack_a, t_deque *stack_b, int bonus);
void	pb_op(t_deque *stack_a, t_deque *stack_b, int bonus);

void	ra_op(t_deque *stack_a, int bonus);
void	rb_op(t_deque *stack_b, int bonus);
void	r_op(t_deque *stack);
void	rra_op(t_deque *stack_a, int bonus);
void	rrb_op(t_deque *stack_b, int bonus);

void	rev_r_op(t_deque *stack);
void	rr_op(t_deque *stack_a, t_deque *stack_b, int bonus);
void	rev_rr_op(t_deque *stack_a, t_deque *stack_b, int bonus);

int		ps_atoi(const char *str);
#endif