/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:18:20 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 22:25:12 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MAXTRIX_H

# include <math.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define X	0
# define Y	1
# define Z	2

typedef double	**t_mat;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

t_mat	*new_mat();
t_mat	*set_mat(t_point point);
t_point	*mat_to_point(t_mat mat);
t_mat	point_to_mat(t_point point);

t_mat	rot_mat(t_mat mat, double radian);
t_point	rot_point(t_point point, double radian);

t_mat	translate_mat(t_mat mat, t_mat trans_mat);
t_point	translate_point(t_point point, t_mat trans_mat);

t_mat	scale_mat(t_point point, double scale);
t_point	scale_point(t_point point, double scale);;

#endif