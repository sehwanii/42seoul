/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:19:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:29 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_node	g_node;

int	send_char(int pid, char c)
{
	int	idx;
	int	odd;

	idx = 7;
	while (idx >= 0)
	{
		if ((c & (1 << idx)) == 0)
		{
			kill(pid, SIGUSR1);
			odd++;
		}
		else
			kill(pid, SIGUSR2);
		usleep(100);
		idx--;
	}
	if (odd & 2 == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
	while (1)
	{
		
	}
}

void	send_line(int pid, char *str)
{
	int is_success;

	while (*str)
	{
		is_success = send_word(pid, *str);
		if (is_success)
			str++;
	}
}

void	sig_handler(int signo, siginfo_t *info, void *context)
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
	while (1)
	{
		kill(pid, SIGUSR1);
		if (g_node.flag == 1)
		{
			g_node.flag = -1;
			send_line(pid, argv[2]);
		}
		write(1,"!",1);
		usleep(1000);
	}
}
