/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/31 22:51:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	store;

void	*eating(t_info *info, t_philo *philo_info)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	printf("%ld%ld %d is eating\n", tv.tv_sec, tv.tv_usec / 1000, philo_info->philo_num);
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

void	*philo_thread(void *arg)
{
	t_philo philo_info;
	t_info *info;
	
	info = (t_info *)arg;
	init_philo(&philo_info, info);
	eating(info, &philo_info);
	sleeping(info, &philo_info);
	thinking(info, &philo_info);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int	i;
	pthread_t	*thread;

	init_info(&info);
	store = 0;
	if (argc == 5 || argc == 6)
	{
		info.philo_total = ft_atoi(argv[1]);
		info.t_die = ft_atoi(argv[2]);
		info.t_eat = ft_atoi(argv[3]);
		info.t_sleep = ft_atoi(argv[4]);
		if (argc == 7)
			info.must_eat_num = ft_atoi(argv[5]);
		printf("philo_num: %d t_die: %d t_eat: %d t_sleep: %d must_eat: %d\n", info.philo_total, info.t_die, info.t_eat, info.t_sleep, info.must_eat_num);
		thread = (pthread_t *)malloc(sizeof(pthread_t) * info.philo_total);
		if (!thread)
			return (1);
		i = 0;
		while (i < info.philo_total)
		{
			if (pthread_create(&thread[i], NULL, philo_thread, (void *)&info) != 0)
				return (1);
			i++;
		}
		usleep(1500 * 1000);
	}
	printf("store: %d\n", store);
	return (0);
}
