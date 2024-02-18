/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:33:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/13 21:49:03 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_point	**map;
	t_map	*map_info;

	map = NULL;
	if (argc != 2)
		exit_msg("Wrong argument!\n");
	map_info = read_map(&map, argv[1]);
	init_points(&map, map_info);
	draw(&map, map_info);
}
