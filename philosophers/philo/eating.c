/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:52:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/12 22:23:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	eating_log(t_info *info, t_philo *philo_info)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		unlock_forks(info, philo_info);
		return (-1);
	}
	if (g_die_flag == 0)
		printf("%ld%03d %d has taken a fork\n", tv.tv_sec,
			(int)(tv.tv_usec / 1000), philo_info->philo_num);
	if (gettimeofday(&tv, NULL) == -1)
	{
		unlock_forks(info, philo_info);
		return (-1);
	}
	if (g_die_flag == 0)
	{
		pthread_mutex_lock(&philo_info->eat_mutex);
		printf("%ld%03d %d is eating\n", tv.tv_sec, (int)(tv.tv_usec / 1000),
			philo_info->philo_num);
		pthread_mutex_unlock(&philo_info->eat_mutex);
	}
	philo_info->eat_date = tv;
	return (0);
}

void	*eating(t_info *info, t_philo *philo_info)
{
	lock_forks(info, philo_info);
	if (eating_log(info, philo_info) == -1)
		return (NULL);
	usleep(info->t_eat * DIGIT);
	unlock_forks(info, philo_info);
	if (info->must_eat_num != -1)
	{
		if (philo_info->eat_count < info->must_eat_num)
		{
			philo_info->eat_count++;
			if (philo_info->eat_count == info->must_eat_num)
				info->philo_eat_count++;
		}
		if (info->philo_eat_count > info->philo_total)
			g_die_flag = 1;
		if (info->philo_eat_count == info->philo_total)
			info->philo_eat_count++;
	}
	return (NULL);
}
