/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:33:47 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/26 14:27:18 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "Deque/deque.h"

//int	push_swap(t_list *stack_a, t_list *stack_b, int arr[]);

int		*parse_input(char *argv[]);
void	init(t_deque *stack_a, t_deque *stack_b, char *argv[]);

void	push_swap_small(t_deque *stack_a, t_deque *stack_b);
void	push_swap_two(t_deque *stack_a);
void	push_swap_three(t_deque *stack_a);
void	push_swap_four(t_deque *stack_a, t_deque *stack_b);
void	push_swap_five(t_deque *stack_a, t_deque *stack_b);

void	sa_op(t_deque *stack_a);
void	sb_op(t_deque *stack_b);
void	s_op(t_deque *stack);
void	ss_op(t_deque *stack_a, t_deque *stack_b);

void	pa_op(t_deque *stack_a, t_deque *stack_b);
void	pb_op(t_deque *stack_a, t_deque *stack_b);

void	ra_op(t_deque *stack_a);
void	rb_op(t_deque *stack_b);
void	r_op(t_deque *stack);
void	rra_op(t_deque *stack_a);
void	rrb_op(t_deque *stack_b);

void	rev_r_op(t_deque *stack);
void	rr_op(t_deque *stack_a, t_deque *stack_b);
void	rev_rr_op(t_deque *stack_a, t_deque *stack_b);

void	ft_write(int fd, char *str);
#endif