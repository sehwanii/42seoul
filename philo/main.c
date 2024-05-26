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
	init_threads(&info, philo, thread);
	while (!info.is_dead && (info.is_done != info.p_num))
		;
	while (idx < info.p_num)
	{
		pthread_join(thread[idx++], NULL);
	}
}

void *test(void *data)
{
    int i;
    int a = ((t_philo*)data)->id;
    for (i = 0; i < 10; i++)
    {
        printf("%d philo's %d work\n", a,i);
    }
    return (void *)(1);
}
