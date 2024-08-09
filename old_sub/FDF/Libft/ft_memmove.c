/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:02:12 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/29 15:54:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	idx = 0;
	if (dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (idx < len)
		{
			*(char *)(dst + idx) = *(char *)(src + idx);
			idx++;
		}
	}
	else
	{
		while (idx < len)
		{
			*(char *)(dst + (len - 1 - idx)) = *(char *)(src + (len - 1 - idx));
			idx++;
		}
	}	
	return (dst);
}
