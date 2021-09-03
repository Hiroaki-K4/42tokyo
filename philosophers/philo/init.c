/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:44:49 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/03 22:37:26 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_philo *philo_info, t_info *info)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	philo_info->die_flag = 0;
	info->philo_count++;
	philo_info->philo_num = info->philo_count;
	philo_info->first_eat = 1;
	philo_info->eat_date = tv;
	return (0);
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
}

void	init_fork_mutex(t_info *info)
{
	int	i;
	
	fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_total);
	if (!fork_mutex)
		exit(1);
	i = 0;
	while (i < info->philo_total)
	{
		if (pthread_mutex_init(&fork_mutex[i], NULL) != 0)
			exit(1);
		i++;
	}
}
