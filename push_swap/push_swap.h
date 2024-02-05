/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:47 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/05 20:16:11 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "Deque/deque.h"

# define ERROR		-1
# define MAX_INT	2147483647

void	push_swap(t_deque *stack_a, t_deque *stack_b);

void	parse_input(char *argv[], t_deque *stack_a);
void	init(t_deque *stack_a, t_deque *stack_b, char *argv[]);
void	check_input(t_deque *stack_a);
void	order_index(t_deque *stack_a);
void	get_index(t_deque *stack_a, int *arr);

void	push_swap_small(t_deque *stack_a, t_deque *stack_b);
void	push_swap_two(t_deque *stack_a);
void	push_swap_three(t_deque *stack_a, t_deque *stack_b);
void	push_swap_four(t_deque *stack_a, t_deque *stack_b);
void	push_swap_five(t_deque *stack_a, t_deque *stack_b);

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
void	rr_op(t_deque *stack_a, t_deque *stack_b);
void	rev_rr_op(t_deque *stack_a, t_deque *stack_b);

void	ft_write(int fd, char *str);
void	rotate_stack(t_deque *stack, int type, t_data data);
void	divide_stack(t_deque *stack_a, t_deque *stack_b, int low, int high);

int		find_place(t_deque *stack, t_data data);
t_data	calc_op_num(t_deque *stack_a, t_deque *stack_b);
void	greedy(t_deque *stack_a, t_deque *stack_b);
#endif