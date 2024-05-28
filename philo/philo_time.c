/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-28 09:14:46 by sehwanii          #+#    #+#             */
/*   Updated: 2024-05-28 09:14:46 by sehwanii         ###   ########.fr       */
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
	while (time * 1000 >= diff_tv(&cur_tv, &start_tv))
	{
		usleep(10);
		gettimeofday(&cur_tv, NULL);
	}
}

void	print_time_stamp(t_philo *philo, const char *action)
{
	t_info			*info;
	struct timeval	cur_tv;

	info = philo->info;
	pthread_mutex_lock(&info->print_mutex);
	gettimeofday(&cur_tv, NULL);
	printf("%ld %d %s\n", (cur_tv.tv_sec - info->start_tv.tv_sec) * 1000 + \
		(cur_tv.tv_usec - info->start_tv.tv_usec) / 1000, philo->id, action);
	pthread_mutex_unlock(&info->print_mutex);	
}