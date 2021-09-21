/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:29:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/21 22:57:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define DIGIT 950

pthread_mutex_t	*g_fork_mutex;
int				g_die_flag;

typedef struct s_philo
{
	int				die_flag;
	int				philo_num;
	int				t_die;
	int				eat_count;
	struct timeval	eat_date;
	pthread_mutex_t	eat_mutex;
}				t_philo;

typedef struct s_info
{
	int	philo_total;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat_num;
	int	philo_count;
	int	die_flag;
	int	philo_eat_count;
	int	max_time;
}				t_info;

int		increment(int i);
int		ft_atoi(const char *nptr);
int		init_fork_mutex(t_info *info);
long	check_time_diff(struct timeval tv, t_philo *philo_info);
void	init_info(t_info *info);
void	init_philo(t_philo *philo_info, t_info *info);
void	*eating(t_info *info, t_philo *philo_info);
void	*sleeping(t_info *info, t_philo *philo_info);
void	*thinking(t_philo *philo_info);
long	check_time_diff(struct timeval tv, t_philo *philo_info);

#endif
