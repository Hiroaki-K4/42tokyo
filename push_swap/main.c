/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/28 22:31:06 by hkubo            ###   ########.fr       */
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

t_bi_list	*last_list(t_bi_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_list(t_bi_list *list, int num)
{
	t_bi_list	*new;

	new = (t_bi_list *)malloc(sizeof(t_bi_list));
	// if (!new)
	// 	return (NULL);
	if (list->start == 1)
	{
		list->data = num;
		list->start = 0;
		list->start = 0;
	}
	else
	{
		new->data = num;
		new->start = 0;
		list = last_list(list);
		new->prev = list;
		new->next = NULL;
		list->next = new;
	}
}

void	show_list(t_bi_list *list)
{
	while (list != NULL)
	{
		printf("data: %d\n", list->data);
		list = list->next;
	}
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

void	top_del(t_bi_list *list)
{
	if (list->next)
	{
		// list->next->prev = NULL;
		list = list->next;
		list->prev = NULL;
	}
	// show_list(list);
	// return (list);
}

void	push_b(t_bi_list *stack_a, t_bi_list *stack_b)
{
	if (stack_b->next == NULL)
	{
		stack_b->data = stack_a->data;
		stack_b->start = 0;
	}
	else
		last_list(stack_b)->next = stack_a;
	// last_list(stack_b)->next = stack_a;
	// stack_a = top_del(stack_a);
	top_del(stack_a);
	show_list(stack_b);
	write(1, "pb\n", 3);
}

// void	push_a(t_bi_list *stack_a, t_bi_list *stack_b)
// {
// 	if (stack_b->start == 1)
// 	{
// 		stack_b->data = stack_a->data;
// 		stack_b->start = 0;
// 	}
// 	else
// 		last_list(stack_b)->next = stack_a;
// 	stack_a = top_del(stack_a);
// 	write(1, "pa\n", 3);
// }

void	swap_a(t_bi_list *stack_a)
{
	int	tmp;
	if (stack_a && stack_a->next)
	{
		tmp = stack_a->data;
		stack_a->data = stack_a->next->data;
		stack_a->next->data = tmp;
	}
	write(1, "sa\n", 3);
}

int	main(int argc, char *argv[])
{
	int i;
	int num;
	t_bi_list stack_a;
	t_bi_list stack_b;
	
	stack_a.prev = NULL;
	stack_a.next = NULL;
	stack_a.start = 1;
	stack_a.data = 0;
	stack_b.prev = NULL;
	stack_b.next = NULL;
	stack_b.start = 1;
	stack_b.data = 0;
	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) == -1)
			error_process();
		num = ft_atoi(argv[i]);
		add_list(&stack_a, num);
		i++;
	}
	// show_list(&stack_a);
	if (duplicate_check(argc, argv) == 1)
		error_process();
	// push_b(&stack_a, &stack_b);
	// show_list(&stack_b);
	// show_list(&stack_a);
	// push_b(stack_a, stack_b);
	// swap_a(&stack_a);
	// show_list(&stack_a);
	show_list(&stack_b);
	// show_list(stack_b);
	return (0);
}