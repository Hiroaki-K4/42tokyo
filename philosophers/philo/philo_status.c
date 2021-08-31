/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:52:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/31 23:00:04 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eating(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	printf("%ld%ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("%ld%ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
	philo_info->eat_date = tv;
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
