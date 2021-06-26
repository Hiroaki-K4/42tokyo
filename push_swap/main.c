/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/26 16:09:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	digit_check(const char *arg)
{
	int i;
	int flag;
	size_t num;

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

void	error_process()
{
	write(1, "Error\n", 6);
	exit(0);
}

void	add_list(t_bi_list *list, int num)
{
	t_bi_list	*new;

	printf("list: %d\n", list->data);
	new = (t_bi_list *)malloc(sizeof(t_bi_list));
	// if (!new)
	// 	return (NULL);
	new->data = num;
	new->prev = list;
	new->next = NULL;
	list->next = new;
}

void	show_list(t_bi_list *list)
{
	while (list != NULL)
	{
		printf("data: %d\n", list->data);
		list = list->next;
	}
}

int	main(int argc, char *argv[])
{
	int i;
	int num;
	t_bi_list *list;

	list->prev = NULL;
	list->next = NULL;
	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) == -1)
			error_process();
		num = ft_atoi(argv[i]);
		printf("arg: %d\n", num);
		add_list(list, num);
		i++;
	}
	show_list(list);
	return (0);
}