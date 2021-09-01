/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:52:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/01 22:50:54 by hkubo            ###   ########.fr       */
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

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("diff: %ld\n", diff_check(tv, philo_info));
	printf("now_sec: %ld before_sec: %ld\n", tv.tv_sec, philo_info->eat_date.tv_sec);
	printf("now_usec: %ld before_usec: %ld\n", tv.tv_usec, philo_info->eat_date.tv_usec);
	printf("%ld%ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	philo_info->eat_date = tv;
	if (philo_info->first_eat == 1)
		philo_info->first_eat = 0;
	usleep(info->t_eat * 1000);
	return (NULL);
}

void	*sleeping(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("%ld%ld %d is sleeping\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	usleep(info->t_sleep * 1000);
	return (NULL);
}

void	*thinking(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	(void)info;
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("%ld%ld %d is thinking\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	return (NULL);
}
