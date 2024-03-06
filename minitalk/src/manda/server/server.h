/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:30:15 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/06 08:32:41 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include "../../../lib/ft_printf/ft_printf.h"
# include "../../../lib/libft/libft.h"
# include "../../../lib/my_utils/my_utils.h"

# define LOCKED	0
# define UNLOCKED 1

typedef struct s_data_node
{
	pid_t	pid;
	int		word_count;
	int		data;
}	t_data_node;

typedef struct s_node
{
	volatile sig_atomic_t	pid;
	volatile sig_atomic_t	flag;
	volatile sig_atomic_t	lock;
}	t_node;

#endif