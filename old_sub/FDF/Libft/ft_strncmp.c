/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:48:54 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/12 14:34:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			idx;

	idx = 0;
	while ((*s1 || *s2) && idx < n)
	{
		c1 = *s1;
		c2 = *s2;
		if (c1 != c2)
			return (c1 - c2);
		else
		{
			s1++;
			s2++;
			idx++;
		}
	}
	return (0);
}
