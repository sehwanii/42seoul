/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 06:54:46 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 20:50:41 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_data_node		g_sig_data;

void	to_binary(int pid, char c)
{
	int	idx;

	idx = 7;
	while (idx >= 0)
	{
		if ((c & (1 << idx)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(20);
		idx--;
	}
}

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static t_deque	deq;

	(void)context;
	if (signo == SIGUSR1)
		g_sig_data.data *= 2;
	else if (signo == SIGUSR2)
		g_sig_data.data = g_sig_data.data * 2 + 1;
	g_sig_data.word_count++;
	if (g_sig_data.word_count == 8)
	{
		ft_printf("%c", (char)(g_sig_data.data));
		dq_add_first(&deq, g_sig_data.data);
		if (g_sig_data.data == 0)
		{
			usleep(100);
			while (!dq_is_empty(&deq))
			{
				to_binary(info->si_pid, dq_pop_last(&deq));
				usleep(10);
			}
		}
		g_sig_data.word_count = 0;
		g_sig_data.data = 0;
	}
}

int	main(void)
{
	const pid_t			id = getpid();
	struct sigaction	sigact;

	ft_printf("%d\n", id);
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		;
}
