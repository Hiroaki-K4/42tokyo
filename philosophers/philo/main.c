/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/03 22:34:09 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// pthread_mutex_t	*fork_mutex;

void	*philo_thread(void *arg)
{
	t_philo philo_info;
	t_info *info;
	
	info = (t_info *)arg;
	init_philo(&philo_info, info);
	while (philo_info.die_flag != 1)
	{
		eating(info, &philo_info);
		sleeping(info, &philo_info);
		thinking(info, &philo_info);
		// printf("die_flag: %d\n", philo_info.die_flag);
	}
	// printf("die2_flag: %d\n", philo_info.die_flag);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int	i;
	pthread_t	*thread;

	init_info(&info);
	if (argc == 5 || argc == 6)
	{
		info.philo_total = ft_atoi(argv[1]);
		if (info.philo_total <= 0)
			return (1);
		info.t_die = ft_atoi(argv[2]);
		info.t_eat = ft_atoi(argv[3]);
		info.t_sleep = ft_atoi(argv[4]);
		if (argc == 7)
			info.must_eat_num = ft_atoi(argv[5]);
		printf("philo_num: %d t_die: %d t_eat: %d t_sleep: %d must_eat: %d\n", info.philo_total, info.t_die, info.t_eat, info.t_sleep, info.must_eat_num);
		thread = (pthread_t *)malloc(sizeof(pthread_t) * info.philo_total);
		if (!thread)
			return (1);
		init_fork_mutex(&info);
		// if (info.philo_total == 1)
		// 	fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 2);
		// else
		// 	fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info.philo_total);
		// if (!fork_mutex)
		// 	return (-1);
		i = 0;
		while (i < info.philo_total)
		{
			if (pthread_create(&thread[i], NULL, philo_thread, (void *)&info) != 0)
				return (1);
			i++;
		}
		// sleep(1500 * 1000);
	}
	return (0);
}
