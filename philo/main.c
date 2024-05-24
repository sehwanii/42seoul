/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:26:56 by sehwjang          #+#    #+#             */
/*   Updated: 2024/02/26 08:46:17 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//number of philosophers
//time to die
//time to eat
//time to sleep
//number of times each philosopher must eat

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

int	main(int argc, char *argv[])
{
	t_info			info;
	struct timeval	tv;

	if (argc == 5 || argc == 6)
		init_info(&info, argc, argv);
	else
		exit_msg("Wrong Argument Number\n");
	init_threads(info);
	printf("Current time: %ld seconds and %d microseconds\n", tv.tv_sec, tv.tv_usec);
}

void	init_info(t_info *info, int argc, char *argv[])
{
	if (argc == 5)
		info->n_eat = -1;
	else
		info->n_eat = my_atoi(argv[5]);
	info->p_num = my_atoi(argv[1]);
	info->t_die = my_atoi(argv[2]);
	info->t_eat = my_atoi(argv[3]);
	info->t_sleep = my_atoi(argv[4]);
	return ;
}

void	init_threads(t_info info)
{
	pthread_t thread_t;
	int	idx;

	idx = 0;
	while (idx < info.p_num)
	{
		pthread_create(&thread_t, NULL, philo, (void *)&info);
	}
}
