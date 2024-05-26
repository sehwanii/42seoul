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
#include <sys/time.h>

long long	diff_tv(struct timeval *tv1, struct timeval *tv2)
{
	long long	sec_diff;
	long long	usec_diff;

	sec_diff = tv1->tv_sec - tv2->tv_sec;
	usec_diff = tv1->tv_usec - tv2->tv_usec;
	return (sec_diff * 1000000 + usec_diff);
}

double	spend_time(struct timeval start_tv, long long time, int idx)
{
	struct timeval	cur_tv;

	gettimeofday(&cur_tv, NULL);
	while (time * 1000 * idx >= diff_tv(&cur_tv, &start_tv))
	{
		usleep(100);
		gettimeofday(&cur_tv, NULL);
	}
	return ((cur_tv.tv_sec - start_tv.tv_sec) * 1000 + \
			(float)(cur_tv.tv_usec - start_tv.tv_usec) / 1000);
}

void	*do_philo(void *data)
{
	struct timeval	start_tv;
	t_philo			*philo;
	double			time;
	int				idx;

	idx = 0;
	philo = data;
	gettimeofday(&start_tv, NULL);
	//while (philo->status != e_die)
	while (idx++ < 10)
	{
		time = spend_time(start_tv, 1, idx);
		printf("%lf\n", time);
	}
	philo->info->is_dead = true;
	return (NULL);
}

