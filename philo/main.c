/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:26:56 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/30 21:09:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//number of philosophers
//time to die
//time to eat
//time to sleep
//number of times each philosopher must eat

#include "philo.h"
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	free_resources(t_info *info, t_philo *philo);

struct timeval	get_eat_time(t_philo *philo)
{
	struct timeval	eat_tv;

	pthread_mutex_lock(&philo->status_mutex[EAT_TIME]);
	eat_tv = philo->eat_tv;
	pthread_mutex_unlock(&philo->status_mutex[EAT_TIME]);
	return (eat_tv);
}

bool	check_philo_die(t_philo *philo)
{
	struct timeval	cur_tv;
	struct timeval	eat_tv;
	int				idx;
	const int		t_die = philo[0].info->t_die;
	t_info			*info;

	info = philo[0].info;
	idx = 0;
	gettimeofday(&cur_tv, NULL);
	while (idx < info->p_num)
	{
		eat_tv = get_eat_time(&philo[idx]);
		//eat_tv = philo[idx].eat_tv;
		//printf("%d!!!!%lld!!!!!\n", idx, diff_tv(&cur_tv, &eat_tv));
		if (diff_tv(&cur_tv, &eat_tv) / 1000 > t_die)//mutex
		{
			print_time_stamp(&philo[idx], DIE_MSG);
			return (true);
		}
		idx++;
	}
	return (false);
}

// bool	check_philo_done(t_philo *philo)
// {
// 	t_info			*info;
// 	int	idx;

// 	info = philo[0].info;
// 	idx = 0;
// 	while (idx < info->p_num)
// 	{
// 		if ()
// 	}
// }

int	main(int argc, char *argv[])
{
	t_info		info;
	t_philo		*philo;
	pthread_t	*thread;
	int			idx;

	philo = NULL;
	thread = NULL;
	idx = 0;
	if (init_main(&info, &philo, argc, argv) == ERROR)
		return (1);
	if (init_threads(&info, &philo, &thread) == ERROR)
	{
		//free_resources(info, philo, thread);
		return (1);
	}
	while (idx < info.p_num)
		pthread_join(thread[idx++], NULL);
	//free_resources(info, philo, thread);
	return (0);
}

// void	check_philo(t_philo *philo)
// {
// 	struct timeval	cur_tv;
// 	int				idx;
// 	const int		t_die = philo[0].info->t_die;
// 	t_info			*info;

// 	info = philo[0].info;
// 	gettimeofday(&cur_tv, NULL);
// 	while (idx < info->p_num)
// 	{
// 		if (diff_tv(&cur_tv, &philo[idx].eat_tv) > t_die)
// 		{
// 			print_time_stamp(&philo[idx], DIE_MSG);
// 			info->is_dead = true;
// 			return ;
// 		}
// 		if (philo[idx].n_eat >= info->n_to_eat)//mutex
// 	}
// }
