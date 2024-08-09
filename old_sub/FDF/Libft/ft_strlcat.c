/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:00:10 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/31 15:11:43 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	idx;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	idx = 0;
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	while (*dst)
		dst++;
	while (*src && idx + dest_len + 1 < dstsize)
	{
		*dst = *src;
		src++;
		dst++;
		idx++;
	}
	*dst = '\0';
	return (dest_len + src_len);
}
