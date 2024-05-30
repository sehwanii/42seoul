/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:08:21 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/30 21:24:41 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_status(t_philo *philo, int eat_num)
{
	pthread_mutex_lock(&philo->status_mutex[IS_DEAD]);
	if (philo->status[IS_DEAD])
	{
		pthread_mutex_unlock(&philo->status_mutex[IS_DEAD]);
		return (IS_DEAD);
	}
	pthread_mutex_unlock(&philo->status_mutex[IS_DEAD]);
	pthread_mutex_lock(&philo->status_mutex[IS_DONE]);
	if (philo->status[IS_DONE])
	{
		pthread_mutex_unlock(&philo->status_mutex[IS_DONE]);	
		return (IS_DONE);
	}
	pthread_mutex_unlock(&philo->status_mutex[IS_DONE]);
	return (NORMAL);
}

void	*do_philo(void *data)
{
	t_philo	*philo;
	int		status;
	int		eat_num;

	philo = data;
	pthread_mutex_lock(&philo->status_mutex[EAT_TIME]);
	philo->eat_tv = philo->info->start_tv;
	pthread_mutex_unlock(&philo->status_mutex[EAT_TIME]);
	if (philo->id % 2)
		usleep(1000);
	eat_num = 0;
	status = get_status(philo, eat_num);
	while (status == NORMAL)
	{
		status = philo_eat(philo);
		if (status == IS_DEAD || status == IS_DONE)
			break ;
		status = philo_sleep(philo);
		if (status == IS_DEAD || status == IS_DONE)
			break ;
		philo_think(philo);
		get_status(philo, ++eat_num);
	}
	return (NULL);
}

