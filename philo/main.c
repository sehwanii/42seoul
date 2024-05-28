/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:26:56 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/26 21:30:25 by sehwjang         ###   ########.fr       */
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

bool	check_philo_die(t_philo *philo)
{
	struct timeval	cur_tv;
	int				idx;
	const int		t_die = philo[0].info->t_die;
	t_info			*info;

	info = philo[0].info;
	idx = 0;
	gettimeofday(&cur_tv, NULL);
	while (idx < info->p_num)
	{
		if (diff_tv(&cur_tv, &philo[idx].eat_tv) > t_die)
		{
			print_time_stamp(&philo[idx], DIE_MSG);
			return (true);
		}
	}
	return (false);
}

bool	check_philo_done(t_philo *philo)
{
	t_info			*info;
	int	idx;

	info = philo[0].info;
	idx = 0;
	while (idx < info->p_num)
	{
		
	}
}

int	main(int argc, char *argv[])
{
	t_info		info;
	t_philo		*philo;
	pthread_t	*thread;
	int			idx;

	philo = NULL;
	thread = NULL;
	idx = 0;
	if (argc == 5 || argc == 6)
		init_info(&info, argc, argv);
	else
	{
		write(2, "Wrong Argument Number\n", 23);
		return (1);
	}
	init_threads(&info, &philo, &thread);
	while (check_philo_die(philo) && check_philo_done(philo))
		;
	while (idx < info.p_num)
	{
		pthread_join(thread[idx++], NULL);
	}
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
