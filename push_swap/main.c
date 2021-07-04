/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/04 16:26:33 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_bi_list **stack_a)
{
	if ((*stack_a)->next->data > (*stack_a)->next->next->data && (*stack_a)->next->data < (*stack_a)->next->next->next->data)
		swap_a(*stack_a);
	else if ((*stack_a)->next->data > (*stack_a)->next->next->data && (*stack_a)->next->next->data > (*stack_a)->next->next->next->data)
	{
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((*stack_a)->next->data > (*stack_a)->next->next->next->data && (*stack_a)->next->next->data < (*stack_a)->next->next->next->data)
		rotate_a(stack_a);
	else if ((*stack_a)->next->data < (*stack_a)->next->next->next->data && (*stack_a)->next->next->data > (*stack_a)->next->next->next->data)
	{
		swap_a(*stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->next->data < (*stack_a)->next->next->data && (*stack_a)->next->data > (*stack_a)->next->next->next->data)
		reverse_rotate_a(stack_a);
}

int	min_data(t_bi_list *stack)
{
	int	min;

	min = stack->data;
	while (stack->next != NULL)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	if (min > stack->data)
		min = stack->data;
	return (min);
}

void	min_to_top(t_bi_list **stack_a)
{
	int	min;
	// while (stack_a)
	
	min = min_data(*stack_a->next);
	printf("min: %d\n", min);
	show_list(*stack_a);
}

void	under_six(t_bi_list **stack_a, t_bi_list **stack_b)
{
	min_to_top(stack_a);
	show_list(*stack_a);
	printf("topb: %d\n", (*stack_b)->data);
}

void	branch_process(int argc, t_bi_list **stack_a, t_bi_list **stack_b)
{
	if (argc <= 2)
		return;
	else if (argc == 3)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
			swap_a(*stack_a);
	}
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc < 7)
		under_six(stack_a, stack_b);
	// else
	
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
		add_stack(&stack_a, num);
		// add_stack(&stack_b, num);
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
	show_list(stack_b);
	return (0);
}
