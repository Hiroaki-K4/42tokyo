/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:32:45 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/01 15:37:58 by hkubo            ###   ########.fr       */
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

int	duplicate_check(int args_count, t_bi_list *stack)
{
	int	*args_list;
	int	i;
	int	j;

	args_list = (int *)malloc(sizeof(int) * args_count);
	if (!args_list)
		exit(1);
	i = -1;
	while (stack->next != NULL)
	{
		args_list[++i] = stack->next->data;
		stack = stack->next;
	}
	i = -1;
	while (++i < args_count)
	{
		j = i;
		while (++j < args_count)
		{
			if (args_list[i] == args_list[j])
				return (1);
		}
	}
	free(args_list);
	return (0);
}
