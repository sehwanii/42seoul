/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:16:20 by sehwanii          #+#    #+#             */
/*   Updated: 2024-05-28 09:16:20 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void    philo_get_fork(t_philo *philo, bool way)
{
    while (true)
    {
        pthread_mutex_lock(philo->mutex[way]);
        if (*(philo->fork[way]) == NOT_OWNED)
            break;
        pthread_mutex_unlock(philo->mutex[way]);
    }
    *(philo->fork[way]) = OWNED;
    pthread_mutex_unlock(philo->mutex[way]);
}

static void    philo_put_fork(t_philo *philo, bool way)
{
    pthread_mutex_lock(philo->mutex[way]);
    *(philo->fork[way]) = NOT_OWNED;
    pthread_mutex_unlock(philo->mutex[way]);
}

void    philo_eat(t_philo *philo, struct timeval *eat_tv)
{
    if (philo->id % 2)
    {
        philo_get_fork(philo, LEFT);
        philo_get_fork(philo, RIGHT);
    }
    else
    {
        philo_get_fork(philo, RIGHT);
        philo_get_fork(philo, LEFT);
    }
    print_time_stamp(philo, EAT_MSG);
    gettimeofday(eat_tv, NULL);
    spend_time(philo->info->t_eat);
    if (philo->id % 2)
    {
        philo_put_fork(philo, LEFT);
        philo_put_fork(philo, RIGHT);
    }
    else
    {
        philo_put_fork(philo, RIGHT);
        philo_put_fork(philo, LEFT);
    }
}

void    philo_sleep(t_philo *philo)
{
    print_time_stamp(philo, SLEEP_MSG);
    spend_time(philo->info->t_sleep);
}

void    philo_think(t_philo *philo)
{
    print_time_stamp(philo, THINK_MSG);
}