/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:25:42 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/10 17:25:30 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*read_map(t_point ***map, char *file_name)
{
	int		fd;
	t_list	*head;
	t_map	*map_info;

	head = NULL;
	map_info = NULL;
	fd = open(file_name, O_RDWR);
	if (fd == -1)
		exit_msg("ERROR : Wrong Input");
	map_info = init_map_info();
	get_input(fd, &head, map_info);
	*map = make_map(&head, map_info);
	ft_lstclear(&head, free);
	close(fd);
	return (map_info);
}
