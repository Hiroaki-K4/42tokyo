/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:43:24 by hkubo             #+#    #+#             */
/*   Updated: 2021/09/22 21:18:42 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_only_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		flag;
	long	ans;

	if (check_only_digit(nptr) == -1)
		return (-1);
	flag = 1;
	i = 0;
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
		if ((ans > INT_MAX && flag == 1) || (ans - 1 > INT_MAX && flag == -1))
			return (-1);
		i++;
	}
	ans = ans * flag;
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
