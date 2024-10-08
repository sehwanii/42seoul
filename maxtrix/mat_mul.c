/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:25:32 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 22:28:49 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	*mul_mat(t_mat m1, t_mat m2)
{
	t_mat	*ret_mat;
	int		i;
	int		j;

	ret_mat = new_mat();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*ret_mat)[i][j] = m1[i][j] * m2[i][j];
		}
	}
	return (ret_mat);
}
