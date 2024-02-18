/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:45:29 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/14 18:03:22 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_grad(t_point p1, t_point p2);
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw(t_point ***map, t_map *map_info)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
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

static double	get_grad(t_point p1, t_point p2)
{
	if (p1.y == p2.y)
		return (0);
	else
		return ((double)(p2.x - p1.x) / (double)(p2.y - p1.y));
}

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	const double	gradient = get_grad(p1, p2);
	const double	constant = -gradient * p1.y + p1.x;
	int				idx;
	int				left_point;
	int				right_point;

	if (gradient == 0)
	{
		idx = p1.x - 1;
		while (++idx <= p2.x)
			my_mlx_pixel_put(data, p1.y, idx, p1.color.rgb);
	}
	else if (fabs(gradient) >= 1)
	{
		left_point = min(p1.x, p2.x);
		right_point = max(p1.x, p2.x);
		idx = left_point - 1;
		while (++idx <= right_point)
			my_mlx_pixel_put(data, (int)round((idx - constant) / gradient), idx, p1.color.rgb); //get_color(left_point->color, right_point->color, 내분점 비율);
	}
	else
	{
		left_point = min(p1.y, p2.y);
		right_point = max(p1.y, p2.y);
		idx = left_point - 1;
		while (++idx <= right_point)
			my_mlx_pixel_put(data, idx, (int)round(gradient * idx + constant), p1.color.rgb);
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
