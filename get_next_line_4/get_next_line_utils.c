/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:34 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/13 20:50:22 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	if (s == NULL)
		return (0);
	cnt = 0;
	while ((s[cnt]))
		cnt++;
	return (cnt);
}

char	*ft_realloc(char *s)
{
	char			*ret;
	const size_t	size = ft_strlen(s);
	size_t			idx;

	idx = 0;
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	while (idx < size)
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	free(s);
	return (ret);
}

size_t	ft_strchr(const char *s, int c)
{
	const size_t	len = ft_strlen(s);
	size_t			i;

	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (i);
}
