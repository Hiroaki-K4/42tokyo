/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/21 22:37:30 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_death_thread(void *arg)
{
	t_philo			*philo_info;
	struct timeval	tv;

	philo_info = (t_philo *)arg;
	while (g_die_flag == 0)
	{
		usleep(5 * DIGIT);
		gettimeofday(&tv, NULL);
		if (check_time_diff(tv, philo_info) > philo_info->t_die
			&& g_die_flag == 0)
		{
			g_die_flag = 1;
			pthread_mutex_lock(&philo_info->eat_mutex);
			printf("%ld%03d %d died\n", tv.tv_sec, (int)(tv.tv_usec / 1000),
				philo_info->philo_num);
			pthread_mutex_unlock(&philo_info->eat_mutex);
		}
	}
	if (g_die_flag == 1)
		philo_info->die_flag = 1;
	return (NULL);
}

void	*philo_thread(void *arg)
{
	t_philo		philo_info;
	t_info		*info;
	pthread_t	monitor_death;

	info = (t_info *)arg;
	init_philo(&philo_info, info);
	if (pthread_create(&monitor_death, NULL, monitor_death_thread,
			(void *)&philo_info) != 0)
	{
		philo_info.die_flag = 1;
		g_die_flag = 1;
	}
	while (philo_info.die_flag != 1)
	{
		eating(info, &philo_info);
		sleeping(info, &philo_info);
		thinking(&philo_info);
	}
	pthread_mutex_destroy(&philo_info.eat_mutex);
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
		pthread_mutex_destroy(&g_fork_mutex[i]);
		i++;
	}
	free(thread);
	free(g_fork_mutex);
	i = 0;
}

int	init(int argc, char *argv[], t_info *info)
{
	init_info(info);
	g_die_flag = 0;
	info->philo_total = ft_atoi(argv[1]);
	if (info->philo_total <= 1)
		return (1);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (info->t_die < 0 || info->t_eat < 0 || info->t_sleep < 0)
		return (1);
	info->max_time = info->t_eat;
	if (info->t_sleep > info->t_eat)
		info->max_time = info->t_sleep;
	if (argc == 6)
	{
		info->must_eat_num = ft_atoi(argv[5]);
		if (info->must_eat_num <= 0)
			return (1);
	}
	if (init_fork_mutex(info) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_info		info;
	pthread_t	*thread;

	if (argc == 5 || argc == 6)
	{
		if (init(argc, argv, &info) == 1)
			return (1);
		thread = (pthread_t *)malloc(sizeof(pthread_t) * info.philo_total);
		if (!thread)
			return (1);
		i = 0;
		while (i < info.philo_total)
		{
			if (pthread_create(&thread[i], NULL, philo_thread,
					(void *)&info) != 0)
				return (1);
			i++;
		}
		while (g_die_flag == 0)
			usleep(5 * DIGIT);
		usleep(info.max_time * DIGIT);
		exit_thread(thread, &info);
	}
	return (0);
}
