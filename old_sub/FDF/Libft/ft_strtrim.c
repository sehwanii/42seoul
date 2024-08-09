/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:26:05 by sehwjang          #+#    #+#             */
/*   Updated: 2023/11/03 18:44:41 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t			idx;
	const size_t	set_len = ft_strlen(set);

	idx = 0;
	while (idx < set_len)
	{
		if (c == *(set + idx))
			return (1);
		idx++;
	}
	return (0);
}

static size_t	find_start_idx(char const *s1, char const *set)
{
	size_t	start_idx;

	start_idx = 0;
	while (*(s1 + start_idx))
	{
		if (is_set(*(s1 + start_idx), set))
			start_idx++;
		else
			break ;
	}
	return (start_idx);
}

static size_t	find_end_idx(char const *s1, char const *set)
{
	size_t	end_idx;

	end_idx = ft_strlen(s1) - 1;
	while (end_idx >= 0)
	{
		if (is_set(*(s1 + end_idx), set))
			end_idx--;
		else
			break ;
	}
	return (end_idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ret_str;
	const size_t	s_len = ft_strlen(s1);
	size_t			start_idx;
	size_t			end_idx;

	start_idx = find_start_idx(s1, set);
	end_idx = find_end_idx(s1, set);
	if (start_idx >= s_len)
	{
		ret_str = (char *)malloc(1);
		if (ret_str == NULL)
			return (0);
		*ret_str = '\0';
		return (ret_str);
	}
	ret_str = (char *)malloc(end_idx - start_idx + 2);
	if (ret_str == NULL)
		return (0);
	ft_strlcpy(ret_str, s1 + start_idx, end_idx - start_idx + 2);
	return (ret_str);
}
