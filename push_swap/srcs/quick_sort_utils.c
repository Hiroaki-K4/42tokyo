/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:09:38 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 16:39:41 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_bi_list *stack)
{
	int	len;

	len = stack_len(stack);
	if (len == 1)
		return (0);
	else if (len > 1)
	{
		while (stack->next->next != NULL)
		{
			if (stack->next->data > stack->next->next->data)
				return (1);
			stack = stack->next;
		}
	}
	return (0);
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

int	stack_len_limit(t_bi_list *stack, int all_min, t_pivot_list **pivot_list)
{
	int	len;

	len = 0;
	while (stack->next != NULL)
	{
		if ((*pivot_list)->len > 0 && stack->next->data
			>= (*pivot_list)->pivot[(*pivot_list)->len - 1])
			return (len);
		if (stack->next->data == all_min)
			return (len);
		stack = stack->next;
		len++;
	}
	return (len);
}

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
