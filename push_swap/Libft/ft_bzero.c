/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:31:08 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/28 14:15:57 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*cptr;

	cptr = (char *)s;
	cnt = 0;
	while (cnt < n)
	{
		*cptr = 0;
		cptr++;
		cnt++;
	}
}
