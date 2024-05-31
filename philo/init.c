/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:58:52 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/30 21:09:42 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *philo, t_info *info, pthread_mutex_t *mutex, bool *fork)
{
	int	idx;

	idx = 0;
	while (idx < info->p_num)
	{
		if (pthread_mutex_init(&mutex[idx], NULL) != OK)
			return (ERROR);
		fork[idx] = false;
		philo[idx].id = idx + 1;
		philo[idx].n_eat = 0;
		philo[idx].is_done = false;
		philo[idx].info = info;
		philo[idx].fork[LEFT] = &fork[idx];
		philo[idx].fork[RIGHT] = &fork[(idx + 1) % info->p_num];
		philo[idx].fork_mutex[LEFT] = &mutex[idx];
		philo[idx].fork_mutex[RIGHT] = &(mutex[(idx + 1) % info->p_num]);
		if (pthread_mutex_init(&(philo[idx].status_mutex[IS_DONE]), NULL) != OK)
			return (ERROR);
		if (pthread_mutex_init(&(philo[idx].status_mutex[IS_DEAD]), NULL) != OK)
			return (ERROR);
		philo[idx].status[IS_DONE] = false;
		philo[idx].status[IS_DEAD] = false;
		gettimeofday(&philo[idx++].eat_tv, NULL);
	}
	return (OK);
}

int	init_threads(t_info *info, t_philo **philo, pthread_t **thread)
{
	pthread_mutex_t	*mutex;
	bool			*fork;
	int				i;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->p_num);
	fork = (bool *)malloc(sizeof(bool) * info->p_num);
	*thread = (pthread_t *)malloc(sizeof(pthread_t) * info->p_num);
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->p_num);
	if (!mutex || !fork || !*thread || !*philo)
		return (ERROR);
	if (init_philo(*philo, info, mutex, fork) == ERROR)
		return (ERROR);
	i = 0;
	while (i < info->p_num)
	{
		if (pthread_create(&(*thread)[i], \
							NULL, do_philo, (void *)(&(*philo)[i])) == ERROR)
			return (ERROR);
		i++;
	}
	return (OK);
}

int	init_info(t_info *info, t_philo **philo, int argc, char *argv[])
{
	if (argc == 5)
		info->n_to_eat = -1;
	else
		info->n_to_eat = my_atoi(argv[5]);
	info->p_num = my_atoi(argv[1]);
	info->t_die = my_atoi(argv[2]);
	info->t_eat = my_atoi(argv[3]);
	info->t_sleep = my_atoi(argv[4]);
	info->philo = *philo;
	if (info->p_num == ERROR || info->t_die == ERROR || info->t_eat == ERROR || \
		info->t_sleep == ERROR || info->n_to_eat == ERROR)
		return (ERROR);
	info->print_status = false;
	if (pthread_mutex_init(&info->print_mutex, NULL) != OK)
		return (ERROR);
	if (pthread_mutex_init(&info->status_mutex, NULL) != OK)
		return (ERROR);
	gettimeofday(&info->start_tv, NULL);
	return (OK);
}

int	init_main(t_info *info, t_philo **philo, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Wrong Argument Number\n", 23);
		return (ERROR);
	}
	if (init_info(info, philo, argc, argv) == ERROR)
	{
		write(2, "ERROR : Arguments should be positive integer\n", 46);
		return (ERROR);
	}
	return (OK);
}
