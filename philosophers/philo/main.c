/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/29 23:10:26 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_philo *philo_info)
{
	philo_info->die_flag = 0;
}

void	*thread1(void *arg)
{
	int	i;
	struct timeval tv;
	t_philo philo_info;
	
	printf("i: %d\n", (t_info *)arg);
	init_philo(&philo_info);
	i = 0;
	while (i < 2)
	{
		usleep(500);
		if (gettimeofday(&tv, NULL) == -1)
			return (NULL);
		printf("%ld%ld %d\n", tv.tv_sec, tv.tv_usec / 1000, philo_info.die_flag);
		i++;
	}
	return (NULL);
}

void	init_info(t_info *info)
{
	info->philo_num = -1;
	info->t_die = -1;
	info->t_eat = -1;
	info->t_sleep = -1;
	info->must_eat_num = -1;
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int	i;
	pthread_t	*thread;

	init_info(&info);
	if (argc == 5 || argc == 6)
	{
		info.philo_num = ft_atoi(argv[1]);
		info.t_die = ft_atoi(argv[2]);
		info.t_eat = ft_atoi(argv[3]);
		info.t_sleep = ft_atoi(argv[4]);
		if (argc == 7)
			info.must_eat_num = ft_atoi(argv[5]);
		printf("philo_num: %d t_die: %d t_eat: %d t_sleep: %d must_eat: %d\n", info.philo_num, info.t_die, info.t_eat, info.t_sleep, info.must_eat_num);
		thread = (pthread_t *)malloc(sizeof(pthread_t) * info.philo_num);
		if (!thread)
			return (1);
		i = 0;
		while (i < info.philo_num)
		{
			if (pthread_create(&thread[i], NULL, thread1, (void *)&info) != 0)
				return (1);
			i++;
		}
		usleep(1500);
	}
	return (0);
}
