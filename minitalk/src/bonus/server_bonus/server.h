/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:30:15 by sehwjang          #+#    #+#             */
/*   Updated: 2024/03/02 20:44:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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