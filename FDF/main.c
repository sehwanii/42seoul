/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:33:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/07/26 15:30:01 by sehwjang         ###   ########.fr       */
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
	if (mlx == NULL)
		exit_msg("mlx error\n");
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	if (mlx_win == NULL)
		exit_msg("mlx error\n");
	map = NULL;
	if (argc != 2)
		exit_msg("Wrong argument\n");
	check_file_name(argv[1]);
	map_info = read_map(&map, argv[1]);
	init_points(&map, map_info);
	mlx_key_hook(mlx_win, key_press, (void *)0);
	mlx_hook(mlx_win, DESTROY_NOTIFY, 0, close_window, (void *)0);
	draw(&map, map_info, mlx, mlx_win);
	while(1);
}
