/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:19:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/02 21:10:50 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>
t_node	g_node;

static void	to_binary(int pid, char *str)
{
	int	idx;
	//int	parity;

	while (*str)
	{
		idx = 7;
		//parity = 0;
		while (idx >= 0)
		{
			if ((*str & (1 << idx)) == 0)
				kill(pid, SIGUSR1);
			else
			{
				kill(pid, SIGUSR2);
				//parity ++;
			}
			usleep(1000);
			idx --;
		}
		// if (parity % 2)
		// 	kill(pid, SIGUSR2);
		// else
		// 	kill(pid, SIGUSR1);
		usleep(1000);
		str++;
	}
	idx = -1;
	while (++idx <= 8)
	{
		ft_printf("1");
		kill(pid, SIGUSR2);
		usleep(1000);
	}
}

static void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		g_node.flag = 1;
	else
		g_node.flag = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigact;
	pid_t				pid;

	if (argc != 3)
		exit_msg("Wrong Arguments");
	g_node.flag = -1;
	pid = my_stoi(argv[1]);
	s_sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigact.sa_mask);
	sigaddset(&s_sigact.sa_mask, SIGUSR1);
	sigaddset(&s_sigact.sa_mask, SIGUSR2);
	s_sigact.sa_flags = SA_RESTART;
	s_sigact.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_sigact, NULL);
	sigaction(SIGUSR2, &s_sigact, NULL);
	int i = 0;
	while (1)
	{
        kill(pid, SIGUSR1);
        usleep(100000); // 10초 대기
		if (g_node.flag == 1)
		{
			to_binary(pid, argv[2]);
			return (0);
		}
        printf("waiting...%d\n",i++);
        fflush(stdout);
		sleep(1);
	}
}