/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:29:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/04 16:43:48 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

// static pthread_mutex_t	*fork_mutex;

typedef struct s_philo
{
	int	die_flag;
	int	philo_num;
	int	first_eat;
	int	t_die;
	struct timeval eat_date;
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
}				t_info;

// #ifdef __cplusplus
// extern "C"{
// #endif /*__cplusplus */

int increment(int i);
int	ft_atoi(const char *nptr);
int	init_philo(t_philo *philo_info, t_info *info);
long	check_time_diff(struct timeval tv, t_philo *philo_info);
void	init_info(t_info *info);
void	*eating(t_info *info, t_philo *philo_info);
void	*sleeping(t_info *info, t_philo *philo_info);
void	*thinking(t_info *info, t_philo *philo_info);
void	init_fork_mutex(t_info *info);
pthread_mutex_t	*fork_mutex;
int	die_flag;

// #ifdef __cplusplus
// }
// #endif /*__cplusplus */


#endif
