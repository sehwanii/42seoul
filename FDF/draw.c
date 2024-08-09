/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:45:29 by sehwjang          #+#    #+#             */
/*   Updated: 2024/04/10 20:27:32 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_point ***map, t_map *map_info, void *mlx, void *mlx_win)
{
	t_data	img;
	int		i;
	int		j;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img.img == NULL)
		exit_msg("MLX Error\n");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	i = -1;
	j = -1;
	while (++i < map_info->row - 1)
	{
		while (++j < map_info->col - 1)
		{
			draw_line(&img, (*map)[i][j], (*map)[i + 1][j]);
			draw_line(&img, (*map)[i][j], (*map)[i][j + 1]);
		}
		draw_line(&img, (*map)[i + 1][j], (*map)[i][j]);
		j = -1;
	}
	while (++j < map_info->col - 1)
		draw_line(&img, (*map)[i][j], (*map)[i][j + 1]);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

static void	draw_line_by_x(t_data *data, t_point p1, t_point p2, float gradient)
{
	const int	l_point = min(p1.x, p2.x);
	const int	r_point = max(p1.x, p2.x);
	int			idx;

	idx = l_point - 1;
	while (++idx <= r_point)
		my_mlx_pixel_put(data, \
		(int)round((idx - (-gradient * p1.y + p1.x)) / gradient), \
		idx, get_color(p1.color, p2.color, \
		(float)(idx - l_point) / (float)(r_point - l_point)));
}

static void	draw_line_by_y(t_data *data, t_point p1, t_point p2, float gradient)
{
	const int	l_point = min(p1.y, p2.y);
	const int	r_point = max(p1.y, p2.y);
	int			idx;

	idx = l_point - 1;
	while (++idx <= r_point)
		my_mlx_pixel_put(data, \
		idx, \
		(int)round(gradient * idx + (-gradient * p1.y + p1.x)), \
		get_color(p1.color, p2.color, \
		(float)(idx - l_point) / (float)(r_point - l_point)));
}

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	const float	gradient = get_grad(p1, p2);

	if (gradient == 0)
	{
		while (p1.x++ <= p2.x)
			my_mlx_pixel_put(data, p1.y, p1.x, p1.color.rgb);
	}
	else if (fabs(gradient) >= 1)
		draw_line_by_x(data, p1, p2, gradient);
	else
		draw_line_by_y(data, p1, p2, gradient);
}
