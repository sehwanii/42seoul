/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:16:20 by sehwanii          #+#    #+#             */
/*   Updated: 2024/06/03 20:40:27 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_get_fork(t_philo *philo, bool way)
{
	while (true)
	{
		pthread_mutex_lock(philo->fork_mutex[way]);
		if (*(philo->fork[way]) == NOT_OWNED)
			break ;
		pthread_mutex_unlock(philo->fork_mutex[way]);
		usleep(200);
	}
	*(philo->fork[way]) = OWNED;
	print_time_stamp(philo, FORK_MSG);
	pthread_mutex_unlock(philo->fork_mutex[way]);
}

static void	philo_put_fork(t_philo *philo, bool way)
{
	pthread_mutex_lock(philo->fork_mutex[way]);
	*(philo->fork[way]) = NOT_OWNED;
	pthread_mutex_unlock(philo->fork_mutex[way]);
}

int	philo_eat(t_philo *philo)
{
	philo_get_fork(philo, LEFT);
	philo_get_fork(philo, RIGHT);
	print_time_stamp(philo, EAT_MSG);
	gettimeofday(&philo->eat_tv, NULL);
	if (spend_time(philo, philo->info->t_eat) == IS_DEAD)
		return (IS_DEAD);
	philo_put_fork(philo, RIGHT);
	philo_put_fork(philo, LEFT);
	if (philo->n_eat == philo->info->n_to_eat)
	{
		pthread_mutex_lock(&philo->info->done_mutex);
		philo->info->done_philo++;
		if (philo->info->done_philo == philo->info->p_num)
			send_done_msg(philo->info);
		pthread_mutex_unlock(&philo->info->done_mutex);
		return (IS_DONE);
	}
	return (NORMAL);
}

int	philo_sleep(t_philo *philo)
{
	print_time_stamp(philo, SLEEP_MSG);
	if (spend_time(philo, philo->info->t_sleep) == IS_DEAD)
		return (IS_DEAD);
	return (NORMAL);
}

void    philo_think(t_philo *philo)
{
    print_time_stamp(philo, THINK_MSG);
	msleep(200);
}