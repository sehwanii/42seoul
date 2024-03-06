/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:33:12 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/26 08:57:12 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int	p_num;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
}	t_info;



//utils.c
int		my_atoi(const char *str);
void	exit_msg(const char *msg);
size_t	ft_strlen(const char *s);

#endif