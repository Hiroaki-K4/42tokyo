/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 22:48:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/10 22:51:52 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*sleeping(t_info *info, t_philo *philo_info)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (g_die_flag == 0)
		printf("%ld%03d %d is sleeping\n", tv.tv_sec, (int)(tv.tv_usec / 1000),
			philo_info->philo_num);
	usleep(info->t_sleep * DIGIT);
	return (NULL);
}

void	*thinking(t_philo *philo_info)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (g_die_flag == 0)
		printf("%ld%03d %d is thinking\n", tv.tv_sec, (int)(tv.tv_usec / 1000),
			philo_info->philo_num);
	return (NULL);
}
