/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:10:51 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/12 15:23:04 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*cptr;

	cptr = (unsigned char *)b;
	cnt = 0;
	while (cnt < len)
	{
		*cptr = (unsigned char)c;
		cptr++;
		cnt++;
	}
	return (b);
}
