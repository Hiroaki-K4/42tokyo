/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:52:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/03 21:40:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	diff_check(struct timeval tv, t_philo *philo_info)
{
	long	before_t;
	long	now_t;
	long	diff;
	
	now_t = (long)(tv.tv_sec * 1000) + (long)(tv.tv_usec / 1000);
	before_t = (long)(philo_info->eat_date.tv_sec * 1000) + (long)(philo_info->eat_date.tv_usec / 1000);
	diff = now_t - before_t;
	return (diff);
}

void	*eating(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	printf("start_eat: %d\n", philo_info->philo_num);
	if (philo_info->philo_num == info->philo_total)
	{
		pthread_mutex_lock(&fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_lock(&fork_mutex[0]);
		printf("lock %d %d\n", 0, philo_info->philo_num - 1);
	}
	else
	{
		pthread_mutex_lock(&fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_lock(&fork_mutex[philo_info->philo_num]);
		printf("lock %d %d\n", philo_info->philo_num - 1, philo_info->philo_num);
	}
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (diff_check(tv, philo_info) > info->t_die)
	{
		printf("die: %d diff: %ld\n", info->t_die, diff_check(tv, philo_info));
		exit(1);
	}
	printf("%ld%lu %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	philo_info->eat_date = tv;
	if (philo_info->first_eat == 1)
		philo_info->first_eat = 0;
	usleep(info->t_eat * 1000);
	if (philo_info->philo_num == info->philo_total)
	{
		pthread_mutex_unlock(&fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_unlock(&fork_mutex[0]);
		printf("unlock %d %d\n", 0, philo_info->philo_num - 1);
	}
	else
	{
		pthread_mutex_unlock(&fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_unlock(&fork_mutex[philo_info->philo_num]);
		printf("unlock %d %d\n", philo_info->philo_num - 1, philo_info->philo_num);
	}
	printf("end_eat: %d\n", philo_info->philo_num);
	return (NULL);
}

void	*sleeping(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	printf("start_sleep: %d\n", philo_info->philo_num);
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("%ld%lu %d is sleeping\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	usleep(info->t_sleep * 1000);
	printf("end_sleep: %d\n", philo_info->philo_num);
	return (NULL);
}

void	*thinking(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	printf("start_think\n");
	(void)info;
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("%ld%lu %d is thinking\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	printf("end_think\n");
	return (NULL);
}
