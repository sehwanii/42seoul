/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/25 01:47:27 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(char *argv[], t_deque *stack_a)
{
	int		idx;
	char	**temp;

	idx = 0;
	while (*argv)
	{
		temp = ft_split(argv[idx], ' ');
		while (*temp == NULL)
			dq_add_last(stack_a, ft_atoi((*temp)++));
		free(temp);
		(*argv)++;
	}
	return ;
}

void	ft_write(int fd, char *str)
{
	if (write(fd, str, ft_Strlen(str)) == -1)
		exit(EXIT_FAILURE);
}

void	free_stack(t_deque *stack_a, t_deque *stack_b){
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
// void	init_stack(t_list *stack_a, t_list *stack_b, int input[])
// {
// 	quick_sort(input);
// 	while (1)
// 	{

// 	}
// }