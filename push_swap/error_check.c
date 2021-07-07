/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:32:45 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/07 22:13:28 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_check(const char *arg)
{
	int		i;
	int		flag;
	size_t	num;

	flag = 1;
	i = 0;
	while (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			flag = flag * (-1);
		if (i == (int)ft_strlen(arg) - 1)
			return (-1);
		i++;
	}
	num = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		num = (10 * num) + (arg[i] - '0');
		i++;
	}
	if ((flag == 1 && num > 2147483647) || (flag == -1 && num > 2147483648))
		return (-1);
	return (0);
}

int	duplicate_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
