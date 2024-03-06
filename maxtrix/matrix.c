/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:23:12 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 22:17:59 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	*new_mat(void)
{
	t_mat	mat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mat = (int **)malloc(sizeof(int *) * 4);
	if (mat == NULL)
	{
		perror("ERROR : MALLOC FAILED - new_mat");
		exit(EXIT_FAILURE);
	}
	while (i < 4)
	{
		mat[i] = (int *)malloc(sizeof(int) * 4);
		if (mat[i] == NULL)
		{
			perror("ERROR : MALLOC FAILED - new_mat");
			exit(EXIT_FAILURE);
		}
		while (j < 4)
			mat[i][j] = 0;
	}
	return (&mat);
}

t_mat	*set_mat(t_point point)
{
	t_mat	mat;

	mat = new_mat();
	mat[0][0] = point.x;
	mat[1][1] = point.y;
	mat[2][2] = point.z;
	mat[3][3] = 1;
	return (&mat);
}