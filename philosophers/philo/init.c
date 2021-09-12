/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:44:49 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/12 21:59:35 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_philo *philo_info, t_info *info)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	philo_info->die_flag = 0;
	info->philo_count++;
	philo_info->philo_num = info->philo_count;
	philo_info->eat_date = tv;
	philo_info->t_die = info->t_die;
	philo_info->eat_count = 0;
	pthread_mutex_init(&philo_info->eat_mutex, NULL);
}

void	init_info(t_info *info)
{
	info->philo_total = -1;
	info->t_die = -1;
	info->t_eat = -1;
	info->t_sleep = -1;
	info->must_eat_num = -1;
	info->philo_count = 0;
	info->die_flag = 0;
	info->philo_eat_count = 0;
}

int	init_fork_mutex(t_info *info)
{
	int	i;

	g_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->philo_total);
	if (!g_fork_mutex)
		return (1);
	i = 0;
	while (i < info->philo_total)
	{
		if (pthread_mutex_init(&g_fork_mutex[i], NULL) != 0)
		{
			free(g_fork_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}
