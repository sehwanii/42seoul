/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:19:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 20:50:11 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_data_node	g_sig_data;

void	to_binary(int pid, char *str)
{
	int			bit_idx;
	int			len_idx;
	int			mask;
	const int	len = ft_strlen(str);

	len_idx = 0;
	mask = 0b01111111;
	while (len_idx <= len)
	{
		bit_idx = 7;
		while (bit_idx >= 0)
		{
			if ((*str & (1 << bit_idx)) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(20);
			bit_idx--;
		}
		str++;
		len_idx++;
	}
}

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;

	if (signo == SIGUSR1)
        g_sig_data.data *= 2;
	else if (signo == SIGUSR2)
        g_sig_data.data = g_sig_data.data * 2 + 1;
    g_sig_data.word_count++;
	if (g_sig_data.word_count >= 8)
	{
		ft_printf("%c", (char)(g_sig_data.data));
		if (g_sig_data.data == 0)
			exit(EXIT_SUCCESS);
		g_sig_data.word_count = 0;
		g_sig_data.data = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;

	if (argc != 3)
		exit_msg("Wrong Arguments");
	to_binary(my_stoi(argv[1]), argv[2]);
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		;
}
