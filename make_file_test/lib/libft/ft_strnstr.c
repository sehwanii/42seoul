/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:19:28 by sehwjang          #+#    #+#             */
/*   Updated: 2023/11/03 16:38:58 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_arr(char *str, char *to_find)
{
	char	*temp_str;
	char	*temp_to_find;

	temp_str = str;
	temp_to_find = to_find;
	while (*temp_to_find)
	{
		if (*temp_to_find != *temp_str)
			return (0);
		temp_str++;
		temp_to_find++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle || !needle)
		return ((char *)haystack);
	while (*haystack && i + ft_strlen(needle) <= len)
	{
		if (haystack[i] == *needle)
		{
			if (check_arr((char *)&haystack[i], (char *)needle))
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
