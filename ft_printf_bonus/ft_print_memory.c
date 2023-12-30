/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:09:24 by sehwjang          #+#    #+#             */
/*   Updated: 2023/11/16 17:31:44 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_ptr(unsigned long long ptr, char *arr);

int	ft_print_memory(void *addr)
{
	unsigned long long	ptr;
	char				arr[16];

	ptr = (unsigned long long)addr;
	print_ptr(ptr, arr);
	write(1, "\n", 1);
	return (16);
}

void	print_ptr(unsigned long long ptr, char *arr)
{
	int		idx;
	char	*hex;

	hex = "0123456789abcdef";
	idx = 0;
	while (idx < 16)
	{
		arr[15 - idx] = hex[ptr % 16];
		ptr /= 16;
		idx++;
	}
	write(1, arr, 16);
}
