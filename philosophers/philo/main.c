/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/29 21:23:22 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread1(void *arg)
{
	// (void)arg;
	usleep(50);
	printf("philo: %d\n", (int)arg);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int	philo_num;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat_num;
	int	i;
	pthread_t	*thread;

	must_eat_num = -1;
	if (argc == 5 || argc == 6)
	{
		philo_num = ft_atoi(argv[1]);
		t_die = ft_atoi(argv[2]);
		t_eat = ft_atoi(argv[3]);
		t_sleep = ft_atoi(argv[4]);
		if (argc == 7)
			must_eat_num = ft_atoi(argv[5]);
		printf("philo_num: %d t_die: %d t_eat: %d t_sleep: %d must_eat: %d\n", philo_num, t_die, t_eat, t_sleep, must_eat_num);
		thread = (pthread_t *)malloc(sizeof(pthread_t) * philo_num);
		if (!thread)
			return (1);
		i = 0;
		while (i < philo_num)
		{
			if (pthread_create(&thread[i], NULL, thread1, &i) != 0)
				return (1);
			i++;
		}
		usleep(100);
		// printf("thread: %ld\n", thread);
	}
	return (0);
}
