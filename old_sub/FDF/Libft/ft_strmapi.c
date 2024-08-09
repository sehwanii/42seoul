/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:03:43 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/28 16:58:25 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			idx;
	const size_t	s_len = ft_strlen(s);
	char			*ret;

	ret = (char *)malloc(s_len + 1);
	if (ret == NULL)
		return (0);
	idx = -1;
	while (++idx < s_len)
		ret[idx] = f(idx, s[idx]);
	ret[idx] = '\0';
	return (ret);
}
