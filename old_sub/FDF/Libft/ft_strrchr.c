/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:43:35 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/28 17:38:48 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = ft_strlen(s);
	while (idx > 0)
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (0);
}
