/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:07:45 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/26 09:45:31 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points(t_point ***map, t_map *map_info)
{
	int	row;
	int	col;
	int	hor_interval;
	int	ver_interval;
	int	z_correction;

	row = -1;
	col = -1;
	ver_interval = (WINDOW_HEIGHT - BEZEL * 2) / (map_info ->row + map_info -> col - 2);
	hor_interval = ver_interval * sqrt(3.0);//(WINDOW_WIDTH - BEZEL) / (map_info ->row + map_info -> col - 2);
	while (++row < map_info -> row)
	{
		col = -1;
		while (++col < map_info -> col)
		{
			// if (map_info->max_height == map_info->min_height)
			// 	z_correction = 0;
			// else
			z_correction = ((*map)[row][col].z - (map_info->max_height + map_info->min_height)/2) * BEZEL / (map_info->max_height - map_info->min_height);
			(*map)[row][col].x = (WINDOW_HEIGHT / 2) - (((map_info ->row + map_info -> col) / 2) - (row + col)) * ver_interval - z_correction;//ver_interval;// * ((WINDOW_HEIGHT - BEZEL)/2);
			(*map)[row][col].y = (WINDOW_WIDTH / 2) + (((map_info ->row - map_info -> col) / 2) - (row - col)) * hor_interval;
			//(*map)[row][col].z = map_info->max_height;
		}
	}
}
