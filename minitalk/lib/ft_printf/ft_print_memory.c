/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:09:24 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/11 15:22:55 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(unsigned long long ptr);

int	ft_print_memory(void *addr)
{
	unsigned long long	ptr;
	int					temp;

	temp = 0;
	if (addr == NULL)
		return (write(1, "0x0", 3));
	ptr = (unsigned long long)addr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	temp = print_ptr(ptr);
	if (temp == -1)
		return (-1);
	return (temp + 2);
}

int	print_ptr(unsigned long long ptr)
{
	int		idx;
	char	*hex;
	int		temp;

	temp = 0;
	hex = "0123456789abcdef";
	idx = 0;
	while (ptr > 0)
	{
		idx = print_ptr(ptr / 16);
		temp = write(1, &hex[ptr % 16], 1);
		if (temp == -1)
			return (-1);
		return (1 + idx);
	}
	return (0);
}
