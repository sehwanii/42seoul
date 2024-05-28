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

void	*do_philo(void *data)
{
	t_philo			*philo;
	int				idx;
	struct timeval	eat_tv;

	philo = data;
	eat_tv = philo->info->start_tv;
	idx = 0;
	//while (philo->status != e_die)
	while (idx++ < 10)
	{
		philo_eat(philo, &eat_tv);
		philo_sleep(philo);
		philo_think(philo);
		//print_time_stamp(philo, "is testing");
	}
	return (NULL);
}

