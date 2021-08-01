/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:15:12 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/01 15:47:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_bi_list **stack)
{
	if ((*stack)->next->data > (*stack)->next->next->data
		&& (*stack)->next->data < (*stack)->next->next->next->data)
		swap_a(*stack, 1);
	else if ((*stack)->next->data > (*stack)->next->next->data
		&& (*stack)->next->next->data > (*stack)->next->next->next->data)
	{
		swap_a(*stack, 1);
		reverse_rotate_a(stack, 1);
	}
	else if ((*stack)->next->data > (*stack)->next->next->next->data
		&& (*stack)->next->next->data < (*stack)->next->next->next->data)
		rotate_a(stack, 1);
	else if ((*stack)->next->data < (*stack)->next->next->next->data
		&& (*stack)->next->next->data > (*stack)->next->next->next->data)
	{
		swap_a(*stack, 1);
		rotate_a(stack, 1);
	}
	else if ((*stack)->next->data < (*stack)->next->next->data
		&& (*stack)->next->data > (*stack)->next->next->next->data)
		reverse_rotate_a(stack, 1);
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
	while (min_data((*stack_a)->next) != (*stack_a)->next->data)
	{
		if (min_data((*stack_a)->next) == last_stack(*stack_a)->data)
			reverse_rotate_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
}

void	args_under_six(t_bi_list **stack_a, t_bi_list **stack_b, int args_count)
{
	int	i;

	i = 3;
	while (i < args_count)
	{
		min_to_top(stack_a);
		push_b(stack_a, stack_b, 1);
		i++;
	}
	sort_three(stack_a);
	i = 3;
	while (i < args_count)
	{
		push_a(stack_a, stack_b, 1);
		i++;
	}
}
