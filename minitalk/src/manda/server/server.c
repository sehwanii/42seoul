/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:12:16 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/06 13:02:14 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_data_node	sig_data;
t_node	g_node;

static void	get_line(int bit);

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (g_node.pid == 0)
		g_node.pid = info->si_pid;
	if (g_node.pid == info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	//write(1, "!", 1);
	//kill(info->si_pid, SIGUSR1);
	if (signo == SIGUSR1)
		g_node.flag = 0;
	else if (signo == SIGUSR2)
		g_node.flag = 1;
	else
	{
		g_node.flag = -1;
		kill(info->si_pid, SIGUSR2);
		return ;
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
	static int	word;
	static int	idx;

	word = word << 1;
	word += bit;
	idx++;
	if (idx >= 8)
	{
		kill(g_node.pid, SIGUSR1);
		write(1, &word, 1);
		idx = 0;
		word = 0;
	}
}

