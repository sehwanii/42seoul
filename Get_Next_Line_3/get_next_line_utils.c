/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:35:48 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/12 16:49:48 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1, '\n');
	char			*ret;

	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	return (ft_memcpy(ret, s1, len + 1));
}

size_t	ft_strlen(const char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*(s + cnt) == c)
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

char	*ft_strchr(const char *s, int c)
{
	const size_t	len = ft_strlen(s);
	size_t			i;

	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	prefix_len = ft_strlen(s1);
	const size_t	suffix_len = ft_strlen(s2);
	const size_t	total_len = prefix_len + suffix_len;
	char			*ret_str;

	ret_str = (char *)malloc(total_len + 1);
	if (ret_str == NULL)
		return (0);
	*ret_str = '\0';
	ft_strlcat(ret_str, s1, prefix_len + 1);
	ft_strlcat(ret_str, s2, total_len + 1);
	return (ret_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret_str;
	const size_t	s_len = ft_strlen(s);

	if (s_len - (size_t)start <= len)
		len = s_len - (size_t)start;
	if (s_len < (size_t)start || len == 0)
	{
		ret_str = (char *)malloc(1);
		if (ret_str == NULL)
			return (0);
		*ret_str = '\0';
	}
	else
	{
		ret_str = (char *)malloc(len + 1);
		if (ret_str == NULL)
			return (0);
		ft_strlcpy(ret_str, s + start, len + 1);
	}
	return (ret_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	if (len < dstsize)
		dstsize = len + 1;
	while (idx < dstsize - 1)
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
	return (len);
}