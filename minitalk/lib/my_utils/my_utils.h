/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:53:43 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/25 21:45:35 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_UTILS_H
# define MY_UTILS_H

# include "../libft/libft.h"

// my_stoi.c
int		my_stoi(char *str);

// my_write.c
void	exit_msg(const char *msg);
void	ft_write(int fd, const char *str);

#endif