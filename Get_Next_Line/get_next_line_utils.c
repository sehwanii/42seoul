/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:35:48 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/31 15:11:43 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	char			*ret;

	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	return (ft_memcpy(ret, s1, len + 1));
}

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	return (cnt);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	while ((dst || src) && idx < n)
	{
		*(char *)(dst + idx) = *(char *)(src + idx);
		idx++;
	}
	return (dst);
}

char	*strmcat(char *save, char *buf)
{
	char			*dst;
	const size_t	save_len = ft_strlen(save);
	const size_t	buf_len = ft_strlen(buf);
	const size_t	dst_len = save_len + buf_len;

	dst = (char *)malloc(dst_len);
	ft_strlcat(dst, save, save_len + 1);
	ft_strlcat(dst, buf, dst_len + 1);
	return (dst);
}

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