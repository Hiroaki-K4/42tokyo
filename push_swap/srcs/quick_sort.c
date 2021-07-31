/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:50:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 17:48:10 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_b_not_sorted(t_bi_list **stack_a, t_bi_list **stack_b,
	t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	int	i;
	int	len;
	int	min;
	int	max;
	int	pivot;

	len = stack_len(*stack_b);
	if (len == 2)
		return (stack_b_len_two(stack_a, stack_b, pivot_list, sort_tool));
	else if (len < 4)
		return (stack_b_len_three(stack_a, stack_b, pivot_list, sort_tool));
	else
	{
		min = stack_min(*stack_b);
		max = stack_max(*stack_b);
		if (sort_tool.sorted_list == NULL)
			pivot = find_pivot(*stack_b, min, max, len);
		else
			pivot = find_pivot_by_sorted(min, len, sort_tool.sorted_list);
		add_pivot(pivot_list, pivot);
		i = -1;
		while (++i < len)
			stack_b_over_three(stack_a, stack_b, pivot, sort_tool);
		return (0);
	}
}

void	first_partition(t_bi_list **stack_a, t_bi_list **stack_b,
	t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	int	i;
	int	min;
	int	max;
	int	len;
	int	pivot;

	min = stack_min(*stack_a);
	max = stack_max(*stack_a);
	len = stack_len(*stack_a);
	if (sort_tool.sorted_list == NULL)
		pivot = find_pivot(*stack_a, min, max, len);
	else
		pivot = find_pivot_by_sorted(min, len, sort_tool.sorted_list);
	i = 0;
	while (i < len)
	{
		if ((*stack_a)->next->data < pivot)
			push_b(stack_a, stack_b, sort_tool.output_flag);
		else
			rotate_a(stack_a, sort_tool.output_flag);
		i++;
	}
	add_pivot(pivot_list, pivot);
}

void	partition_to_b(t_bi_list **stack_a, t_bi_list **stack_b,
	t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	int	pivot;
	int	count;
	int	min;
	int	len;

	min = stack_min_limit(*stack_a, sort_tool.all_min, pivot_list);
	len = stack_len_limit(*stack_a, sort_tool.all_min, pivot_list);
	if (sort_tool.sorted_list == NULL)
		pivot = find_pivot(*stack_a, min, stack_max(*stack_a), len);
	else
		pivot = find_pivot_by_sorted(min, len, sort_tool.sorted_list);
	add_pivot(pivot_list, pivot);
	count = 0;
	while (len-- > 0)
	{
		if ((*stack_a)->next->data < pivot)
			push_b(stack_a, stack_b, sort_tool.output_flag);
		else
		{
			count++;
			rotate_a(stack_a, sort_tool.output_flag);
		}
	}
	while (count-- > 0)
		reverse_rotate_a(stack_a, sort_tool.output_flag);
}

void	partition_a(t_bi_list **stack_a, t_bi_list **stack_b,
	t_sort_tool sort_tool, t_pivot_list **pivot_list)
{
	int	min;
	int	len;

	min = stack_min_limit(*stack_a, sort_tool.all_min, pivot_list);
	len = stack_len_limit(*stack_a, sort_tool.all_min, pivot_list);
	if (len == 0 && (*stack_a)->next->data != sort_tool.all_min)
	{
		rotate_a(stack_a, sort_tool.output_flag);
		delete_min_pivot(pivot_list);
	}
	else if (len == 1)
		rotate_a(stack_a, sort_tool.output_flag);
	else if (len == 2)
		arg_two_operations(stack_a, sort_tool, min);
	else if (len > 2)
		partition_to_b(stack_a, stack_b, pivot_list, sort_tool);
}

void	quick_sort(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag,
	int *sorted_list)
{
	int				top_flag;
	t_pivot_list	*pivot_list;
	t_sort_tool		sort_tool;

	top_flag = 0;
	sort_tool = init_list(*stack_a, output_flag, sorted_list, &pivot_list);
	while (sorted_check(*stack_a) == 1 || (*stack_b)->next != NULL)
	{
		if (top_flag == 1 && (*stack_a)->next->data == sort_tool.all_min
			&& (*stack_b)->next != NULL)
			return ;
		if ((*stack_b)->next != NULL)
		{
			if (stack_b_not_empty(stack_a, stack_b, pivot_list, sort_tool) == 1)
				top_flag = 1;
		}
		else
		{
			if (top_flag == 0)
				first_partition(stack_a, stack_b, &pivot_list, sort_tool);
			else
				partition_a(stack_a, stack_b, sort_tool, &pivot_list);
		}
	}
	free_pivot_list(pivot_list);
}
