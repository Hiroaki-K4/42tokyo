/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 20:38:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_bi_list	*last_list(t_bi_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	add_list(t_bi_list *list, int num)
{
	t_bi_list	*new;

	new = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!new)
		return (-1);
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
	return (0);
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
		(*list) = (*list)->next;
		(*list)->prev = NULL;
	}
}

int	main(int argc, char *argv[])
{
	int i;
	int num;
	t_bi_list *stack_a;
	t_bi_list *stack_b;
	
	stack_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_a)
		return (-1);
	stack_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_b)
		return (-1);
	stack_init(&stack_a, &stack_b);
	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) == -1)
			error_process();
		num = ft_atoi(argv[i]);
		add_list(stack_a, num);
		add_list(stack_b, num);
		i++;
	}
	if (duplicate_check(argc, argv) == 1)
		error_process();
	// push_a(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	swap_b(stack_b);
	show_list(stack_b);
	// show_list(stack_b);
	return (0);
}
