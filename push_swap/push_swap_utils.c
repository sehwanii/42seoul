/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:40 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/24 17:05:15 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_input(char *argv[])
{
	int		idx;
	int		*arr;
	char	**temp;

	idx = 0;
	arr = (int *)malloc(10);
	while (*argv)
	{
		if (ft_strlen(*argv) == 1)
			arr[idx++] = ft_atoi(*argv);
		else
		{
			temp = ft_split(argv[idx], ' ');
			while (*temp == NULL)
				arr[idx++] = ft_atoi((*temp)++);
			free(temp);
		}	
		(*argv)++;
	}
	return (arr);
}


// void	init_stack(t_list *stack_a, t_list *stack_b, int input[])
// {
// 	quick_sort(input);
// 	while (1)
// 	{

// 	}
// }