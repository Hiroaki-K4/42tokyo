/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/06 23:10:39 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_bi_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->data > stack_a->next->data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	stack_min(t_bi_list *stack)
{
	int	min;

	min = stack->next->data;
	while (stack->next != NULL)
	{
		if (min > stack->next->data)
			min = stack->next->data;
		stack = stack->next;
	}
	if (min > stack->data)
		min = stack->data;
	return (min);
}

int	stack_max(t_bi_list *stack)
{
	int	max;

	max = stack->next->data;
	while (stack->next != NULL)
	{
		if (max < stack->next->data)
			max = stack->next->data;
		stack = stack->next;
	}
	if (max < stack->data)
		max = stack->data;
	return (max);
}

int	stack_len(t_bi_list *stack)
{
	int	len;

	len = 0;
	while (stack->next != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int find_pivot(t_bi_list *stack, int min, int max)
{
	while (stack->next != NULL)
	{
		if (stack->next->data != min && stack->next->data != max)
			return (stack->next->data);
		stack = stack->next;
	}
	if (stack->data != min && stack->data != max)
		return (stack->data);
	return (0);
}

void	quick_sort(t_bi_list **stack_a, t_bi_list **stack_b)
{
	// t_bi_list	*first;
	int	i;
	int	len;
	int	min;
	int	max;
	int pivot;

	while (sorted_check(*stack_a) == 1 || (*stack_b)->next != NULL)
	{
		if ((*stack_b)->next != NULL)
		{
			show_list(*stack_a);
			printf("b_emp\n");
			show_list(*stack_b);
			printf("b_emp\n");
		}
		else
		{
			min = stack_min(*stack_a);
			max = stack_max(*stack_a); 
			pivot = find_pivot(*stack_a, min, max);
			len = stack_len(*stack_a);
			printf("len: %d\n", len);
			i = 0;
			while (i < len)
			{
				if ((*stack_a)->next->data < pivot)
					push_b(stack_a, stack_b);
				else
					rotate_a(stack_a);
				i++;
			}
		}
		min = stack_min(*stack_a);
		max = stack_max(*stack_a); 
		pivot = find_pivot(*stack_a, min, max);
		// printf("pivot: %d\n", pivot);
	}
	// printf("first: %d\n", first->data);
	printf("topa: %d\n", (*stack_a)->data);
	printf("topb: %d\n", (*stack_b)->data);
}

void	branch_process(int argc, t_bi_list **stack_a, t_bi_list **stack_b)
{
	if (argc <= 2)
		return ;
	else if (sorted_check((*stack_a)->next) == 0)
		return ;
	else if (argc == 3)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
			swap_a(*stack_a);
	}
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc < 7)
		under_six(stack_a, stack_b, argc);
	else
		quick_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			num;
	t_bi_list	*stack_a;
	t_bi_list	*stack_b;

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
		add_stack(&stack_a, num);
		i++;
	}
	if (duplicate_check(argc, argv) == 1)
		error_process();
	branch_process(argc, &stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// swap_b(stack_a);
	// swap_b(stack_b);
	// swap_ab(&stack_a, &stack_b);
	// rotate_a(&stack_a);
	// rotate_b(&stack_b);
	// rotate_ab(&stack_a, &stack_b);
	// reverse_rotate_a(&stack_a);
	// reverse_rotate_b(&stack_b);
	// reverse_rotate_ab(&stack_a, &stack_b);
	show_list(stack_a);
	printf("~~~~~\n");
	show_list(stack_b);
	return (0);
}
