/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:33:12 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/24 17:09:49 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define LEFT	0
# define RIGHT	1

# define OWNED		true
# define NOT_OWNED	false

# define IS_DONE	0
# define IS_DEAD	1

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"
# define DIE_MSG	"died"

typedef struct s_info
{
	int				p_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_to_eat;
	pthread_mutex_t	print_mutex;
	struct timeval	start_tv;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				n_eat;
	bool			is_done;
	t_info			*info;
	pthread_mutex_t	*fork_mutex[2];
	bool			*fork[2];
	pthread_mutex_t	status_mutex[2];
	bool			status[2];
	struct timeval	eat_tv;
}	t_philo;

struct s_thread_info 
{
	pthread_t thread_id; /* pthread_create()가 반환한 ID */
	int thread_num; /* 애플리케이션 정의 스레드 # */
	char *argv_string; /* 명령줄 인수에서 */
}	t_thread_info;


//utils.c
int		my_atoi(const char *str);
void	exit_msg(const char *msg);
size_t	ft_strlen(const char *s);

//philo.c
void	*do_philo(void *data);

//init.c
void	init_threads(t_info *info, t_philo **philo, pthread_t **thread);
void	init_philo(t_philo *philo, t_info *info);
void	init_info(t_info *info, int argc, char *argv[]);

//philo_time.c
void		spend_time(long long time);
void		print_time_stamp(t_philo *philo, const char *action);
long long	diff_tv(struct timeval *tv1, struct timeval	*tv2);
//philo_action.c
void    philo_eat(t_philo *philo, struct timeval *eat_tv);
void    philo_sleep(t_philo *philo);
void    philo_think(t_philo *philo);

#endif