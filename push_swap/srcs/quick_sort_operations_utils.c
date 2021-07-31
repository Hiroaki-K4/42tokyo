/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_operations_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:49:21 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 16:56:47 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_two_operations(t_bi_list **stack_a, t_sort_tool sort_tool, int min)
{
	if ((*stack_a)->next->data == min)
	{
		rotate_a(stack_a, sort_tool.output_flag);
		rotate_a(stack_a, sort_tool.output_flag);
	}
	else
	{
		swap_a(*stack_a, sort_tool.output_flag);
		rotate_a(stack_a, sort_tool.output_flag);
		rotate_a(stack_a, sort_tool.output_flag);
	}
}

int	stack_b_len_two(t_bi_list **stack_a, t_bi_list **stack_b,
	t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	push_a(stack_a, stack_b, sort_tool.output_flag);
	push_a(stack_a, stack_b, sort_tool.output_flag);
	rotate_a(stack_a, sort_tool.output_flag);
	rotate_a(stack_a, sort_tool.output_flag);
	delete_min_pivot(pivot_list);
	return (1);
}

int	stack_b_len_three(t_bi_list **stack_a, t_bi_list **stack_b,
	t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	int	len;
	int	min;

	len = stack_len(*stack_b);
	while (len > 0)
	{
		min = stack_min(*stack_b);
		if ((*stack_b)->next->data == min)
		{
			push_a(stack_a, stack_b, sort_tool.output_flag);
			rotate_a(stack_a, sort_tool.output_flag);
			len--;
		}
		else
			rotate_b(stack_b, sort_tool.output_flag);
	}
	delete_min_pivot(pivot_list);
	return (1);
}

void	stack_b_over_three(t_bi_list **stack_a, t_bi_list **stack_b,
	int pivot, t_sort_tool sort_tool)
{
	if ((*stack_b)->next->data >= pivot)
		push_a(stack_a, stack_b, sort_tool.output_flag);
	else
		rotate_b(stack_b, sort_tool.output_flag);
}
