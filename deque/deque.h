/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:58:59 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/24 22:47:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE	1
# define FALSE	0

typedef int	t_data;

typedef struct s_node
{
	t_data			data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
}	t_deque;

void	dq_init(t_deque *pdeq);
int		dq_is_empty(t_deque *pdeq);

void	dq_add_first(t_deque *pdeq, t_data data);
void	dq_add_last(t_deque *pdeq, t_data data);

t_data	dq_pop_first(t_deque *pdeq);
t_data	dq_pop_last(t_deque *pdeq);

t_data	dq_get_first(t_deque *pdeq);
t_data	dq_get_last(t_deque *pdeq);

#endif