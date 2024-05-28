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
	bool			*fork;
	int				idx;
	
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->p_num);
	fork = (bool *)malloc(sizeof(bool) * info->p_num);
	idx = 0;
	while (idx < info->p_num)
	{
		pthread_mutex_init(&mutex[idx], NULL);
		fork[idx] = false;
		philo[idx].id = idx + 1;
		philo[idx].n_eat = 0;
		philo[idx].is_done = false;
		philo[idx].info = info;
		philo[idx].fork[LEFT] = &fork[idx];
		philo[idx].fork[RIGHT] = &fork[(idx + 1) % info->p_num];
		philo[idx].fork_mutex[LEFT] = &mutex[idx];
		philo[idx].fork_mutex[RIGHT] = &(mutex[(idx + 1) % info->p_num]);
		pthread_mutex_init(&(philo[idx].status_mutex[IS_DONE]), NULL);
		pthread_mutex_init(&(philo[idx].status_mutex[IS_DEAD]), NULL);
		philo[idx].status[IS_DONE] = false;
		philo[idx].status[IS_DEAD] = false;
		gettimeofday(&philo[idx++].eat_tv, NULL);
	}
}

void	init_threads(t_info *info, t_philo **philo, pthread_t **thread)
{
	int	idx;

	*thread = (pthread_t *)malloc(sizeof(pthread_t) * info->p_num);
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->p_num);
	init_philo(*philo, info);
	idx = 0;
	while (idx < info->p_num)
	{
		pthread_create(&(*thread)[idx], NULL, do_philo, (void *)(&(*philo)[idx]));
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
	pthread_mutex_init(&info->print_mutex, NULL);
	gettimeofday(&info->start_tv, NULL);
	return ;
}
