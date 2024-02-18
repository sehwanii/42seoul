/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:07:45 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/14 18:29:56 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <stdio.h>

void	init_points(t_point ***map, t_map *map_info)
{
	int	row;
	int	col;
	int	hor_interval;
	int	ver_interval;

	row = 0;
	col = 0;
	ver_interval = (WINDOW_HEIGHT - BEZEL) / (map_info ->row + map_info -> col - 2);
	//ver_interval = ver_interval / 2;
	hor_interval = ver_interval * sqrt(3.0);//(WINDOW_WIDTH - BEZEL) / (map_info ->row + map_info -> col - 2);
	(void)map;
	while (row < map_info -> row)
	{
		col = 0;
		while (col < map_info -> col)
		{
			printf("%d!",map_info->max_height);
			(*map)[row][col].x = (WINDOW_HEIGHT / 2) - (((map_info ->row + map_info -> col) / 2) - (row + col)) * ver_interval - (*map)[row][col].z;//ver_interval;// * ((WINDOW_HEIGHT - BEZEL)/2);
			printf("%d %d\n", (WINDOW_HEIGHT / 2) - (((map_info ->row + map_info -> col) / 2) - (row + col)) * ver_interval, (*map)[row][col].x);
			(*map)[row][col].y = (WINDOW_WIDTH / 2) + (((map_info ->row - map_info -> col) / 2) - (row - col)) * hor_interval;
			//(*map)[row][col].z = map_info->max_height;
			printf("%d ", (*map)[row][col].color.rgb);
			col++;
		}
		row++;
		printf("\n");
	}
}
