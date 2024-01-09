/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:10:09 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/09 12:01:10 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	idx;
// 	size_t	len;

// 	idx = 0;
// 	len = 0;
// 	while (src[len])
// 		len ++;
// 	if (dstsize == 0)
// 		return (len);
// 	if (len < dstsize)
// 		dstsize = len + 1;
// 	while (idx < dstsize - 1)
// 	{
// 		*dst = *src;
// 		dst++;
// 		src++;
// 		idx++;
// 	}
// 	*dst = '\0';
// 	return (len);
// }
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;
	size_t	idx;
	
	len = 0;
	idx = 0;
	while (s1[len])
		len++;
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	while ((ret || s1) && idx < len + 1)
	{
		*(char *)(ret + idx) = *(char *)(s1 + idx);
		idx++;
	}
	return (ret);

}
size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	return (cnt);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	prefix_len;
	size_t	suffix_len;
	size_t	total_len;
	char			*ret_str;

	if (s1 == NULL)
	{
		s1 = ft_strdup(s2);
		return ((char *)s1);
	}
	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	total_len = prefix_len + suffix_len;
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
	char	*ret_str;
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (s_len <= len + (size_t)start)
		len = s_len - (size_t)start;
	if (s_len < (size_t)start || len == 0)
		return (0);
	else
	{
		ret_str = (char *)malloc(len + 1);
		if (ret_str == NULL)
			return (0);
		ret_str[0] = '\0';
		ft_strlcat(ret_str, s + start, len + 1);
	}
	return (ret_str);
}
