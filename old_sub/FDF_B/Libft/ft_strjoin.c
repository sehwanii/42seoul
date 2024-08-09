/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:49:51 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/28 17:10:51 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
