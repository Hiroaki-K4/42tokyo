/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/04 22:11:21 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_death_thread(void *arg)
{
	t_philo *philo_info;
	struct timeval tv;

	philo_info = (t_philo *)arg;
	while (die_flag == 0)
	{
		usleep(5 * 1000);
		if (gettimeofday(&tv, NULL) == -1)
			return (NULL);
		if (check_time_diff(tv, philo_info) > philo_info->t_die)
		{
			die_flag = 1;
			printf("%ld%03ld %d died\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
		}
	}
	if (die_flag == 1)
		philo_info->die_flag = 1;
	return (NULL);
}

void	*philo_thread(void *arg)
{
	t_philo philo_info;
	t_info *info;
	pthread_t	monitor_death;
	
	info = (t_info *)arg;
	init_philo(&philo_info, info);
	if (pthread_create(&monitor_death, NULL, monitor_death_thread, (void *)&philo_info) != 0)
		return (NULL);
	while (philo_info.die_flag != 1)
	{
		eating(info, &philo_info);
		sleeping(info, &philo_info);
		thinking(&philo_info);
	}
	pthread_join(monitor_death, NULL);
	return (NULL);
}

void	exit_thread(pthread_t *thread, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_total)
	{
		pthread_join(thread[i], NULL);
		pthread_mutex_destroy(&fork_mutex[i]);
		i++;
	}
	free(thread);
	free(fork_mutex);
	i = 0;
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int	i;
	pthread_t	*thread;

	init_info(&info);
	die_flag = 0;
	if (argc == 5 || argc == 6)
	{
		info.philo_total = ft_atoi(argv[1]);
		if (info.philo_total <= 1)
			return (1);
		info.t_die = ft_atoi(argv[2]);
		info.t_eat = ft_atoi(argv[3]);
		info.t_sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			info.must_eat_num = ft_atoi(argv[5]);
			if (info.must_eat_num <= 0)
				return (1);
		}
		thread = (pthread_t *)malloc(sizeof(pthread_t) * info.philo_total);
		if (!thread)
			return (1);
		init_fork_mutex(&info);
		i = 0;
		while (i < info.philo_total)
		{
			if (pthread_create(&thread[i], NULL, philo_thread, (void *)&info) != 0)
				return (1);
			i++;
		}
		while (die_flag == 0)
		{
			usleep(5 * 1000);
			continue ;
		}
		exit_thread(thread, &info);
	}
	return (0);
}
