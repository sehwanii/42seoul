/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:58:52 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/26 21:30:19 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, t_info *info)
{
	pthread_mutex_t	*mutex;
	int				idx;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->p_num);
	idx = 0;
	while (idx < info->p_num)
	{
		philo[idx].id = idx + 1;
		philo[idx].info = info;
		philo[idx].fork[LEFT] = false;
		philo[idx].fork[RIGHT] = false;
		philo[idx].mutex[LEFT] = mutex[idx];
		philo[idx].mutex[RIGHT] = mutex[(idx + 1) % info->p_num];
		philo[idx++].n_eat = 0;
	}
}

void	init_threads(t_info *info, t_philo *philo, pthread_t *thread)
{
	int	idx;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * info->p_num);
	philo = (t_philo *)malloc(sizeof(t_philo) * info->p_num);
	init_philo(philo, info);
	idx = 0;
	while (idx < info->p_num)
	{
		pthread_create(&thread[idx], NULL, do_philo, (void *)&philo[idx]);
		idx++;
	}
	idx = 0;
}


void	init_info(t_info *info, int argc, char *argv[])
{
	if (argc == 5)
		info->n_to_eat = -1;
	else
		info->n_to_eat = my_atoi(argv[5]);
	info->p_num = my_atoi(argv[1]);
	info->t_die = my_atoi(argv[2]);
	info->t_eat = my_atoi(argv[3]);
	info->t_sleep = my_atoi(argv[4]);
	info->is_dead = false;
	info->is_done = 0;
	return ;
}
