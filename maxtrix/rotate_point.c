/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:57:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 22:24:40 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	make_x_rot_mat(t_mat *rot_mat, double rot_angle);
static void	make_y_rot_mat(t_mat *rot_mat, double rot_angle);
static void	make_z_rot_mat(t_mat *rot_mat, double rot_angle);

void	rotate_point(t_point *p1, double rot_angle, int axis)
{
	/*
	1. 점을 행렬로
	2. 회전 행렬 생성
	3. 행렬 곱하기 행렬
	4. 행렬을 점으로
	*/
	t_mat	origin_mat;
	t_mat	rot_mat;
	t_mat	mod_mat;

	origin_mat = set_mat(*p1);
	rot_mat = make_rot_mat(rot_angle, axis);
	mod_mat = mat_mul(origin_mat, rot_mat);
	p1 = mat_to_point(mod_mat);
}

t_mat	*make_rot_mat(double rot_angle, int axis)
{
	t_mat	*rot_mat;

	rot_mat = new_mat();
	if (axis == X)
		make_x_rot_mat(rot_mat, rot_angle);
	else if (axis == Y)
		make_y_rot_mat(rot_mat, rot_angle);
	else if (axis == Z)
		make_z_rot_mat(rot_mat, rot_angle);
	else
		exit_msg("Wrong axis");
	return (rot_mat);
}

static void	make_x_rot_mat(t_mat *rot_mat, double rot_angle)
{
	(*rot_mat)[0][0] = 1;
	(*rot_mat)[1][1] = cos(rot_angle);
	(*rot_mat)[1][2] = -sin(rot_angle);
	(*rot_mat)[2][1] = sin(rot_angle);
	(*rot_mat)[2][2] = cos(rot_angle);
	(*rot_mat)[3][3] = 1;
}

static void	make_y_rot_mat(t_mat *rot_mat, double rot_angle)
{
	(*rot_mat)[0][0] = cos(rot_angle);
	(*rot_mat)[0][2] = sin(rot_angle);
	(*rot_mat)[1][1] = 1;
	(*rot_mat)[2][0] = -sin(rot_angle);
	(*rot_mat)[2][2] = cos(rot_angle);
	(*rot_mat)[3][3] = 1;
}


static void	make_z_rot_mat(t_mat *rot_mat, double rot_angle)
{
	(*rot_mat)[0][0] = cos(rot_angle);
	(*rot_mat)[0][1] = -sin(rot_angle);
	(*rot_mat)[1][0] = sin(rot_angle);
	(*rot_mat)[1][1] = cos(rot_angle);
	(*rot_mat)[2][2] = 1;
	(*rot_mat)[3][3] = 1;
}

t_point	translate_point(t_point p1, t_point move_point)
{
	/*
	1. 점을 행렬로
	2. translate 행렬 생성
	3. 행렬 곱셈
	4. 행렬을 점으로
	*/
}

t_point	scale_point(t_point t);