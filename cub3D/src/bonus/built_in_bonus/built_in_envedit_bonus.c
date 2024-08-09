/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_envedit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:31:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/03 19:04:36 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "built_in_bonus.h"
#include "ft_error_bonus.h"
#include "libft.h"

static t_bi_error	_handle_one_argu(char *argu, t_env *env)
{
	char	*find;
	char	*name;
	int		location;

	if ('0' <= argu[0] && argu[0] <= '9')
		return (ft_error(error_export, invalid_identifier, argu));
	find = ft_strchr(argu, '=');
	if (find == NULL && _find_specific_char(argu) == NO_SPECIFIC_CHAR)
		return (ft_error(error_export, need_assignment, argu));
	else if (find == NULL || find == argu)
		return (ft_error(error_export, invalid_identifier, argu));
	location = ft_strchr(argu, '=') - argu;
	name = ft_substr(argu, 0, location);
	if (_find_specific_char(name) != NO_SPECIFIC_CHAR)
	{
		free(name);
		return (ft_error(error_export, invalid_identifier, argu));
	}
	if (update_envlist(env->envlist, name, &argu[location + 1]) == false)
		env->envlist = add_envlist(env->envlist, ft_strdup(argu));
	free(name);
	return (use_errno);
}

int	ft_export(char **cmds, t_env *env)
{
	t_bi_error	record;
	t_bi_error	now;
	int			i;

	if (cmds[1] == NULL)
		return (ft_env(cmds, env));
	if (cmds[1][0] == '-')
		return (ft_error(error_export, not_support_option, cmds[1]));
	record = use_errno;
	i = 0;
	while (cmds[++i] != NULL)
	{
		now = _handle_one_argu(cmds[i], env);
		if (record == use_errno)
			record = now;
	}
	if (record != use_errno)
		return (get_bi_errcode(record));
	return (0);
}

int	ft_unset(char **cmds, t_env *env)
{
	int	i;

	i = 1;
	while (cmds[i] != NULL)
	{
		if (cmds[i][0] == '-')
		{
			if (i == 1)
				return (ft_error(error_unset, not_support_option, cmds[i]));
			return (ft_error(error_unset, invalid_identifier, cmds[i]));
		}
		if (_find_specific_char(cmds[i]) != NO_SPECIFIC_CHAR)
			return (ft_error(error_unset, invalid_identifier, cmds[i]));
		if (find_env(env->envlist, cmds[i]) != NULL)
			delete_envlist(env->envlist, cmds[i]);
		i++;
	}
	return (0);
}
