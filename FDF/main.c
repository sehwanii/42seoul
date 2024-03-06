/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:33:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/23 14:46:15 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_point	**map;
	t_map	*map_info;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	map = NULL;
	if (argc != 2)
		exit_msg("Wrong argument!\n");
	map_info = read_map(&map, argv[1]);
	init_points(&map, map_info);
	draw(&map, map_info, mlx, mlx_win);
}
