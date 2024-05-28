/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:08:21 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/26 21:26:47 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_philo(void *data)
{
	t_philo			*philo;
	//t_info			*info;
	//int				idx;

	philo = data;
	//info = philo->info;
	pthread_mutex_lock(&philo->status_mutex[EAT_TIME]);
	philo->eat_tv = philo->info->start_tv;
	pthread_mutex_unlock(&philo->status_mutex[EAT_TIME]);
	// if (philo->id % 2)
	// 	usleep(1000);
	//idx = 0;
	while (true)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		//print_time_stamp(philo, "is testing");
	}
	return (NULL);
}

