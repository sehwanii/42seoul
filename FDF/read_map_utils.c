/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:58:43 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/31 18:15:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_input(int fd, t_list **head, t_map *map_info)
{
	char	*line;
	t_list	*new;
	int		idx;

	idx = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		new = ft_lstnew(line);
		if (new == NULL)
			exit_msg("Malloc Failed\n");
		ft_lstadd_back(head, new);
		line = get_next_line(fd);
		idx ++;
	}
	map_info ->row = idx;
	return ;
}

t_map	*init_map_info(void)
{
	t_map	*map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (map_info == NULL)
		exit_msg("Malloc Failed\n");
	map_info ->col = -1;
	map_info ->row = -1;
	map_info ->max_height = MIN_INT;
	map_info ->min_height = MAX_INT;
	return (map_info);
}

t_point	**make_map(t_list **head, t_map *map_info)
{
	t_list	*cur;
	t_point	**map;
	char	**data;
	int		idx;

	idx = 0;
	cur = *head;
	map = (t_point **)malloc(sizeof(t_point *) * map_info -> row);
	if (map == NULL)
		exit_msg("Malloc Failed\n");
	while (cur != NULL)
	{
		data = ft_split(cur ->content, ' ');
		if (data == NULL)
			exit_msg("Malloc Failed\n");
		map[idx] = parse_line(data, map_info, idx);
		free_split(data);
		idx ++;
		cur = cur -> next;
	}
	return (map);
}

t_point	*parse_line(char **line, t_map *map_info, int row)
{
	int		idx;
	t_point	*map_row;

	idx = 0;
	while (line[idx] != NULL && line[idx][0] != '\n')
		idx++;
	if (map_info ->col != -1 && map_info -> col != idx)
		exit_msg("Invaild Map\n");
	map_info -> col = idx;
	map_row = (t_point *)malloc(sizeof(t_point) * map_info -> col);
	if (map_row == NULL)
		exit_msg("Malloc Failed\n");
	idx = 0;
	while (idx < map_info -> col)
	{
		set_point(&map_row[idx], row, idx, line[idx]);
		if (map_info->max_height < map_row[idx].z)
			map_info->max_height = map_row[idx].z;
		else if (map_info->min_height > map_row[idx].z)
			map_info->min_height = map_row[idx].z;
		idx ++;
	}
	return (map_row);
}

void	set_point(t_point *point, int x, int y, char *point_value)
{
	char	**temp;
	char	**data;
	int		color;

	temp = ft_split(point_value, ',');
	data = temp;
	point->x = x;
	point->y = y;
	point->z = fdf_atoi(*(temp++));
	if (*temp == NULL)
	{
		point->color.rgb = 0xffffff;
		point->color.red = 255;
		point->color.green = 255;
		point->color.blue = 255;
	}
	else
	{
		color = my_stoi(*temp);
		point->color.rgb = color;
		point->color.blue = color % 256;
		point->color.green = (color / 256) % 256;
		point->color.red = ((color / 256) / 256) % 256;
	}
	free_split(data);
}
