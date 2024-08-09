/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:07:45 by sehwjang          #+#    #+#             */
/*   Updated: 2024/04/29 21:33:55 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	calc_zcorrection(t_point ***map, t_map *map_info, int row, int col);

void	init_points(t_point ***map, t_map *map_info)
{
	int		row;
	int		col;
	double	hor;
	double	ver;
	int		z_correction;

	row = -1;
	col = -1;
	ver = (double)(HEIGHT - BEZEL * 2) / (map_info ->row + map_info -> col);
	hor = ver * sqrt(3.0);
	while (++row < map_info -> row)
	{
		col = -1;
		while (++col < map_info -> col)
		{
			z_correction = calc_zcorrection(map, map_info, row, col);
			(*map)[row][col].x = (HEIGHT / 2) - \
			(((map_info ->row + map_info -> col) / 2) - (row + col)) * ver \
			- z_correction;
			(*map)[row][col].y = (WIDTH / 2) + \
			(((map_info ->row - map_info -> col) / 2) - (row - col)) * hor;
		}
	}
}

static	int	calc_zcorrection(t_point ***map, t_map *map_info, int row, int col)
{
	if (map_info->max_height == map_info->min_height)
		return (0);
	return (((*map)[row][col].z - \
		(map_info->max_height + map_info->min_height) / 2) * BEZEL \
		/ (map_info->max_height - map_info->min_height));
}
