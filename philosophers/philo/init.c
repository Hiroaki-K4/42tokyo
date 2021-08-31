/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:44:49 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/31 23:03:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_philo *philo_info, t_info *info)
{
	philo_info->die_flag = 0;
	info->philo_count++;
	philo_info->philo_num = info->philo_count;
	philo_info->first_eat = 1;
}

void	init_info(t_info *info)
{
	info->philo_total = -1;
	info->t_die = -1;
	info->t_eat = -1;
	info->t_sleep = -1;
	info->must_eat_num = -1;
	info->philo_count = 0;
}
