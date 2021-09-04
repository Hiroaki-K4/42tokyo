/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:52:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/04 22:42:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	check_time_diff(struct timeval tv, t_philo *philo_info)
{
	long	before_t;
	long	now_t;
	long	diff;

	now_t = (long)(tv.tv_sec * 1000) + (long)(tv.tv_usec / 1000);
	before_t = (long)(philo_info->eat_date.tv_sec * 1000)
		+ (long)(philo_info->eat_date.tv_usec / 1000);
	diff = now_t - before_t;
	return (diff);
}

void	lock_forks(t_info *info, t_philo *philo_info)
{
	if (philo_info->philo_num == info->philo_total)
	{
		if (philo_info->philo_num % 2 == 1)
			usleep(200);
		pthread_mutex_lock(&g_fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_lock(&g_fork_mutex[0]);
	}
	else
	{
		if (philo_info->philo_num % 2 == 1)
			usleep(200);
		pthread_mutex_lock(&g_fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_lock(&g_fork_mutex[philo_info->philo_num]);
	}
}

void	unlock_forks(t_info *info, t_philo *philo_info)
{
	if (philo_info->philo_num == info->philo_total)
	{
		pthread_mutex_unlock(&g_fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_unlock(&g_fork_mutex[0]);
	}
	else
	{
		pthread_mutex_unlock(&g_fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_unlock(&g_fork_mutex[philo_info->philo_num]);
	}
}

void	eating_log(t_info *info, t_philo *philo_info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		unlock_forks(info, philo_info);
		return (NULL);
	}
	if (g_die_flag == 0)
		printf("%ld%03ld %d has taken a fork\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	if (gettimeofday(&tv, NULL) == -1)
	{
		unlock_forks(info, philo_info);
		return (NULL);
	}
	if (g_die_flag == 0)
		printf("%ld%03ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	philo_info->eat_date = tv;
}

void	*eating(t_info *info, t_philo *philo_info)
{
	// struct timeval	tv;

	lock_forks(info, philo_info);
	// if (gettimeofday(&tv, NULL) == -1)
	// {
	// 	unlock_forks(info, philo_info);
	// 	return (NULL);
	// }
	// if (g_die_flag == 0)
	// 	printf("%ld%03ld %d has taken a fork\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	// if (gettimeofday(&tv, NULL) == -1)
	// {
	// 	unlock_forks(info, philo_info);
	// 	return (NULL);
	// }
	// if (g_die_flag == 0)
	// 	printf("%ld%03ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	// philo_info->eat_date = tv;
	eating_log(info, philo_info);
	usleep(info->t_eat * 1000);
	unlock_forks(info, philo_info);
	if (info->must_eat_num != -1)
	{
		if (philo_info->eat_count < info->must_eat_num)
		{
			philo_info->eat_count++;
			if (philo_info->eat_count == info->must_eat_num)
				info->philo_eat_count++;
		}
		if (info->philo_eat_count == info->philo_total)
			g_die_flag = 1;
	}
	return (NULL);
}

void	*sleeping(t_info *info, t_philo *philo_info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (g_die_flag == 0)
		printf("%ld%03ld %d is sleeping\n", tv.tv_sec, tv.tv_usec / 1000,
			philo_info->philo_num);
	usleep(info->t_sleep * 1000);
	return (NULL);
}

void	*thinking(t_philo *philo_info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (g_die_flag == 0)
		printf("%ld%03ld %d is thinking\n", tv.tv_sec, tv.tv_usec / 1000,
			philo_info->philo_num);
	return (NULL);
}
