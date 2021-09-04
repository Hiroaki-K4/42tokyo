/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:52:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/04 21:42:53 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	check_time_diff(struct timeval tv, t_philo *philo_info)
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

	if (philo_info->philo_num == info->philo_total)
	{
		pthread_mutex_lock(&fork_mutex[philo_info->philo_num - 1]);
		pthread_mutex_lock(&fork_mutex[0]);
	}
	else
	{
		if (pthread_mutex_lock(&fork_mutex[philo_info->philo_num - 1]) != 0)
			printf("error\n");
		if (pthread_mutex_lock(&fork_mutex[philo_info->philo_num]) != 0)
			printf("error\n");
	}
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (die_flag == 0)
		printf("%ld%03ld %d has taken a fork\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (die_flag == 0)
		printf("%ld%03ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	philo_info->eat_date = tv;
	usleep(info->t_eat * 1000);
	if (philo_info->philo_num == info->philo_total)
	{
		if (pthread_mutex_unlock(&fork_mutex[philo_info->philo_num - 1]) != 0)
			printf("error\n");
		if (pthread_mutex_unlock(&fork_mutex[0]) != 0)
			printf("error\n");
	}
	else
	{
		if (pthread_mutex_unlock(&fork_mutex[philo_info->philo_num - 1]) != 0)
			printf("error\n");
		if (pthread_mutex_unlock(&fork_mutex[philo_info->philo_num]) != 0)
			printf("error\n");
	}
	if (info->must_eat_num != -1)
	{
		if (philo_info->eat_count < info->must_eat_num)
		{
			philo_info->eat_count++;
			if (philo_info->eat_count == info->must_eat_num)
				info->philo_eat_count++;
		}
		if (info->philo_eat_count == info->philo_total)
			die_flag = 1;
	}
	return (NULL);
}

void	*sleeping(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (die_flag == 0)
		printf("%ld%03ld %d is sleeping\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	usleep(info->t_sleep * 1000);
	return (NULL);
}

void	*thinking(t_philo *philo_info)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	if (die_flag == 0)
		printf("%ld%03ld %d is thinking\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	return (NULL);
}
