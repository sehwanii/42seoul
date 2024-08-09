/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:39:04 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/24 21:42:01 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_signal_bonus.h"
#include <stdio.h>
#include <readline/readline.h>

void	set_rl_signal(void)
{
	set_signal_ctrl_print_off();
	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	rl_signal_event_hook = rl_sig_handler;
}

void	set_child_signal(void)
{
	set_signal_ctrl_print_on();
	signal(SIGINT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_heredoc_signal(void)
{
	signal(SIGINT, sig_handler);
	rl_signal_event_hook = heredoc_sig_handler;
}

void	set_signal_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
