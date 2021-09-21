/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:43:24 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/21 23:03:32 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	ft_atoi(const char *nptr)
// {
// 	int		i;
// 	int		flag;
// 	int		ans;

// 	flag = 1;
// 	i = 0;
// 	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
// 		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			flag = -1;
// 		i++;
// 	}
// 	ans = 0;
// 	while (nptr[i] >= '0' && nptr[i] <= '9')
// 	{
// 		ans = (ans * 10) + (nptr[i] - '0');
// 		i++;
// 	}
// 	ans = ans * flag;
// 	return (ans);
// }

int	ft_atoi(const char *nptr)
{
	int		i;
	int		flag;
	long	ans;

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
		if ((ans > INT_MAX && flag == 1) || (ans > INT_MAX + 1 && flag == -1))
			return (-1);
		i++;
	}
	ans = ans * flag;
	printf("min: %d\n", INT_MIN);
	printf("max: %d\n", INT_MAX);
	// printf("ans: %ld\n", ans);
	return (ans);
}

long	check_time_diff(struct timeval tv, t_philo *philo_info)
{
	long	before_t;
	long	now_t;
	long	diff;

	now_t = (long)(tv.tv_sec * 1000) + (long)(tv.tv_usec / 1000);
	before_t = (long)(philo_info->eat_date.tv_sec * 1000)
		+ (long)(philo_info->eat_date.tv_usec / 1000);
	diff = now_t - before_t;
	return (diff);
}
