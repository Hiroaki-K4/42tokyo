/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:15:12 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/04 17:15:50 by hkubo            ###   ########.fr       */
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
	while (min_data((*stack_a)->next) != (*stack_a)->next->data)
	{
		if (min_data((*stack_a)->next) == last_stack(*stack_a)->data)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

void	under_six(t_bi_list **stack_a, t_bi_list **stack_b, int argc)
{
	int	i;

	i = 4;
	while (i < argc)
	{
		min_to_top(stack_a);
		push_b(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	i = 4;
	while (i < argc)
	{
		push_a(stack_a, stack_b);
		i++;
	}
}
