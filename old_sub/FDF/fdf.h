/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:21:43 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/23 18:48:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>
# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

# define ERROR			-1
# define MALLOC_ERROR	-1

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define BEZEL			100

# define MIN_INT		-2147483648
# define MAX_INT		2147483647

typedef struct s_color{
	int	rgb;
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}	t_point;

typedef struct s_map
{
	int	row;
	int	col;
	int	max_height;
	int	min_height;
}	t_map;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_view{
	int		x;
	int		y;
	int		z;
	double	rad;
	double	scale;
}	t_view;

int	my_stoi(char *str);

t_map	*read_map(t_point ***map, char *file_name);
void	get_input(int fd, t_list **head, t_map *map_info);
t_map	*init_map_info(void);
t_point	**make_map(t_list **head, t_map *map_info);
t_point	*parse_line(char **line, t_map *map_info, int row);
void	set_point(t_point *point, int x, int y, char *point_value);

void	draw(t_point ***map, t_map *map_info, void *mlx, void *mlx_win);
void	draw_line(t_data *data, t_point p1, t_point p2);

void	init_points(t_point ***map, t_map *map_info);

void	exit_msg(const char *msg);
int		fdf_atoi(const char *str);
int	max(int a, int b);
int min(int a, int b);

//draw_utils.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(t_color color1, t_color color2, double idx);
double	get_grad(t_point p1, t_point p2);
#endif