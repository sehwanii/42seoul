/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:28:35 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 20:50:52 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include "../../../lib/ft_printf/ft_printf.h"
# include "../../../lib/libft/libft.h"
# include "../../../lib/my_utils/my_utils.h"
# include "../../../lib/deque/deque.h"

typedef struct s_data_node
{
	pid_t	pid;
	int		word_count;
	int		data;
}	t_data_node;

#endif