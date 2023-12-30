/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:05:12 by sehwjang          #+#    #+#             */
/*   Updated: 2023/12/23 09:42:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
