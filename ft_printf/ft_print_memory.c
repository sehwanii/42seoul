/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:09:24 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/10 16:47:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(unsigned long long ptr);

int	ft_print_memory(void *addr)
{
	unsigned long long	ptr;

	if (addr == NULL)
		return (write(1, "0x0", 3));
	ptr = (unsigned long long)addr;
	write(1,"0x",2);
	return (print_ptr(ptr)+2);
}

int	print_ptr(unsigned long long ptr)
{
	int		idx;
	char	*hex;

	hex = "0123456789abcdef";
	idx = 0;
	while (ptr > 0)
	{
		idx = print_ptr(ptr / 16);
		write(1, &hex[ptr % 16], 1);
		return (1 + idx);
	}
	return (0);
}
