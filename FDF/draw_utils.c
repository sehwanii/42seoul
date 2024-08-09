/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:32:57 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/30 18:05:42 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_rgb(int red, int green, int blue)
{
	int	ret;

	ret = red * 256;
	ret += green;
	ret *= 256;
	ret += blue;
	return (ret);
}

int	get_color(t_color color1, t_color color2, double idx)
{
	t_color	ret;

	ret.red = (int)(color1.red * (1 - idx) + color2.red * idx);
	ret.green = (int)(color1.green * (1 - idx) + color2.green * idx);
	ret.blue = (int)(color1.blue * (1 - idx) + color2.blue * idx);
	return (get_rgb(ret.red, ret.green, ret.blue));
}

double	get_grad(t_point p1, t_point p2)
{
	if (p1.y == p2.y)
		return (0);
	else
		return ((double)(p2.x - p1.x) / (double)(p2.y - p1.y));
}
