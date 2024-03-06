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

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 4)
		info.n_eat = -1;
	else if (argc == 5)
		init_info(&info, argv);
	else
		exit_msg("Wrong Argument Number\n");
}

void	init_info(t_info *info, char *argv[])
{
	info->p_num = my_atoi(argv[1]);
	info->t_die = my_atoi(argv[2]);
	info->t_eat = my_atoi(argv[3]);
	info->t_sleep = my_atoi(argv[4]);
}
