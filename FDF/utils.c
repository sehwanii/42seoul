/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:11:48 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/10 17:38:49 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	close_window(void)
{
	exit(0);
	return (0);
}

void	free_split(char **arr)
{
	char	**temp;

	if (arr == NULL)
		return ;
	temp = arr;
	while (*arr)
	{
		free(*(arr++));
	}
	free(temp);
}

void	check_file_name(char *file_name)
{
	const int	len = ft_strlen(file_name);

	if (len < 4)
		exit_msg("Error : Wrong file name\n");
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'f' || \
		file_name[len - 2] != 'd' || file_name[len - 1] != 'f')
		exit_msg("Error : Wrong file name\n");
}
