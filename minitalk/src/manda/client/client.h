/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:28:35 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/06 13:04:32 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include "../../../lib/ft_printf/ft_printf.h"
# include "../../../lib/libft/libft.h"
# include "../../../lib/my_utils/my_utils.h"

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