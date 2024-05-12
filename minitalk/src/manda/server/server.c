/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:12:16 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/02 21:14:39 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
t_node	g_node;

static void	get_line(int bit);

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (g_node.pid == 0)
	{
		g_node.pid = info->si_pid;
		kill(info->si_pid, SIGUSR1);
	}
	else if (g_node.pid != info->si_pid)
	{
		ft_printf("%d__%d_______________\n", g_node.pid, info->si_pid);
		kill(info->si_pid, SIGUSR2);
	}
	else
	{
		if (signo == SIGUSR1)
			g_node.flag = 0;
		else if (signo == SIGUSR2)
			g_node.flag = 1;
		else
			g_node.flag = -1;
	}
	return ;
}

int	main(void)
{
	const pid_t			id = getpid();
	struct sigaction	s_sigact;

	g_node.flag = -1;
	s_sigact.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", id);
	sigemptyset(&s_sigact.sa_mask);
	sigaddset(&s_sigact.sa_mask, SIGUSR1);
	sigaddset(&s_sigact.sa_mask, SIGUSR2);
	sigaddset(&s_sigact.sa_mask, SIGINT);
	s_sigact.sa_flags = SA_RESTART;
	s_sigact.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_sigact, NULL);
	sigaction(SIGUSR2, &s_sigact, NULL);
	while (1)
	{
		if (g_node.flag != -1)
		{
			get_line(g_node.flag);
			g_node.flag = -1;
		}
	}
}

static void	get_line(int bit)
{
	static unsigned char	word;
	static int	idx;

	word = word << 1;
	word += bit;
	idx++;
	ft_printf("%d", bit);
	if (idx >= 8)
	{
		if (word == 255)
		{
			ft_printf("!!!!!!!!!!");
			g_node.pid = 0;
			idx = 0;
			word = 0;
			return ;
		}
		else
		{
			//word = word >> 1;
			write(1, &word, 1);
			idx = 0;
			word = 0;
		}
		printf("\n");
		fflush(stdout);
		idx =0;
	}
	g_node.flag = -1;
}