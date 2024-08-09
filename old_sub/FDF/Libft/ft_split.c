/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:56:57 by sehwjang          #+#    #+#             */
/*   Updated: 2023/11/03 18:49:12 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	change_zero(char *str, char c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (str[idx] == c)
			str[idx] = '\0';
		idx++;
	}
}

static int	count_word(char *s, size_t len)
{
	size_t	idx;
	size_t	word_num;

	word_num = 0;
	idx = 1;
	while (idx <= len)
	{
		if (s[idx] == '\0' && s[idx - 1] != '\0')
			word_num++;
		idx++;
	}
	return (word_num);
}

static int	word_split(char *str, char **ret, size_t len)
{
	size_t	idx;
	size_t	jdx;

	idx = 0;
	jdx = 0;
	if (str[idx] != '\0')
	{
		ret[jdx] = ft_strdup(&str[idx]);
		if (ret[jdx] == NULL)
			return (jdx);
		jdx++;
		idx++;
	}
	while (idx < len)
	{
		if (str[idx] == '\0' && str[idx + 1] != '\0')
		{
			ret[jdx] = ft_strdup(&str[idx + 1]);
			if (ret[jdx] == NULL)
				return (jdx);
			jdx++;
		}
		idx++;
	}
	return (jdx);
}

static char	**get_return(char *str, char **ret, size_t s_len, size_t word_num)
{
	size_t			malloc_num;
	size_t			idx;

	malloc_num = 0;
	idx = 0;
	malloc_num = word_split(str, ret, s_len);
	if (malloc_num != word_num)
	{
		while (idx <= malloc_num)
			free(ret[idx++]);
		free(ret);
		free(str);
		return (0);
	}
	ret[word_num] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	const size_t	s_len = ft_strlen(s);
	size_t			word_num;
	char			*str;
	char			**ret;
	size_t			idx;

	str = ft_strdup(s);
	if (str == NULL)
		return (0);
	change_zero(str, c, s_len);
	word_num = count_word(str, s_len);
	idx = 0;
	ret = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!ret)
	{
		free(str);
		return (0);
	}
	if (get_return(str, ret, s_len, word_num) == 0)
		return (0);
	free(str);
	return (ret);
}
