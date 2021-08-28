/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:27:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/28 21:59:25 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		flag;
	int		ans;

	flag = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	ans = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = (ans * 10) + (nptr[i] - '0');
		i++;
	}
	ans = ans * flag;
	return (ans);
}

void	*thread1(void *arg)
{
	(void)arg;
	sleep(1);
	printf("aaa\n");
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int	philo_num;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat_num;
	pthread_t	thread;

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
		if (pthread_create(&thread, NULL, thread1, NULL) == 0)
			printf("ok\n");
		printf("thread: %d\n", thread);
	}
	return (0);
}
