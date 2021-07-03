/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 17:32:15 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

	printf("ok3\n");
	new = (t_bi_list *)malloc(sizeof(t_bi_list));
	// if (!new)
	// 	return (NULL);
	if (list->start == 1)
	{
		list->data = num;
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

void	top_del(t_bi_list **list)
{
	if ((*list)->next)
	{
		// list->next->prev = NULL;
		(*list) = (*list)->next;
		(*list)->prev = NULL;
	}
	// show_list(list);
	// return (list);
}

void	push_b(t_bi_list **stack_a, t_bi_list **stack_b)
{
	// if (stack_b->next != NULL)
	// {
		// stack_b->data = stack_a->data;
		// stack_b->start = 0;
	// }
	// else
	// 	last_list(stack_b)->next = stack_a;

	//stack_aの先頭をstack_bの先頭に入れる処理を書く
	
	// last_list(stack_b)->next = stack_a;
	// stack_a = top_del(stack_a);
	top_del(stack_a);
	show_list(*stack_a);
	show_list(*stack_b);
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
	// t_bi_list stack_a_sub;
	// t_bi_list *stack_a = &stack_a_sub;
	t_bi_list *stack_a;
	t_bi_list *stack_b;
	
	if (!(stack_a = (t_bi_list *)malloc(sizeof(t_bi_list))))
		return (-1);
	// stack_a = NULL;
	// stack_b = NULL;
	// stack_a = &stack_a_sub;
	stack_a->prev = NULL;
	stack_a->next = NULL;
	stack_a->start = 1;
	stack_a->data = 0;
	printf("ok\n");
	stack_b->prev = NULL;
	stack_b->next = NULL;
	stack_b->start = 1;
	stack_b->data = 0;
	i = 1;
	printf("ok2: %s\n", argv[0]);
	while (i < argc)
	{
		printf("ok2.1: %s\n", argv[i]);
		if (digit_check(argv[i]) == -1)
			error_process();
		printf("ok2.5\n");
		num = ft_atoi(argv[i]);
		add_list(stack_a, num);
		add_list(stack_b, num);
		i++;
	}
	printf("ok4\n");
	// show_list(&stack_a);
	// show_list(&stack_b);
	if (duplicate_check(argc, argv) == 1)
		error_process();
	push_b(&stack_a, &stack_b);
	// show_list(&stack_b);
	show_list(stack_a);
	// push_b(stack_a, stack_b);
	// swap_a(&stack_a);
	// show_list(&stack_a);
	// show_list(&stack_b);
	// show_list(stack_b);
	return (0);
}