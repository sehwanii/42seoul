/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:14:46 by sehwanii          #+#    #+#             */
/*   Updated: 2024/05/29 20:55:48 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long long	diff_tv(struct timeval *tv1, struct timeval	*tv2)
{
	long long	sec_diff;
	long long	usec_diff;

	sec_diff = tv1->tv_sec - tv2->tv_sec;
	usec_diff = tv1->tv_usec - tv2->tv_usec;
	return (sec_diff * 1000000 + usec_diff);
}

void	spend_time(long long time)
{
	struct timeval	start_tv;
	struct timeval	cur_tv;	

	gettimeofday(&start_tv, NULL);
	gettimeofday(&cur_tv, NULL);
	usleep(time * 660);
	while (time * 1000 >= diff_tv(&cur_tv, &start_tv))
	{
		usleep(1000);
		gettimeofday(&cur_tv, NULL);
	}
}

void	print_time_stamp(t_philo *philo, const char *action)
{
	t_info			*info;
	struct timeval	cur_tv;

	info = philo->info;
	while (true)
	{
		pthread_mutex_lock(&info->print_mutex);
		if (info->print_status == false)
		{
			info->print_status = true;
			pthread_mutex_unlock(&info->print_mutex);	
			break ;
		}
		pthread_mutex_unlock(&info->print_mutex);
	}
	gettimeofday(&cur_tv, NULL);
	printf("%ld %d %s\n", (cur_tv.tv_sec - info->start_tv.tv_sec) * 1000 + \
		(cur_tv.tv_usec - info->start_tv.tv_usec) / 1000, philo->id, action);
	pthread_mutex_lock(&info->print_mutex);
	info->print_status = false;
	pthread_mutex_unlock(&info->print_mutex);
}