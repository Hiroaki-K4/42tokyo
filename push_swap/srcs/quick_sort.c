/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:50:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 16:38:56 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_b_len_two(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	push_a(stack_a, stack_b, sort_tool.output_flag);
	push_a(stack_a, stack_b, sort_tool.output_flag);
	rotate_a(stack_a, sort_tool.output_flag);
	rotate_a(stack_a, sort_tool.output_flag);
	delete_min_pivot(pivot_list);
	return (1);
}

int	stack_b_not_sorted(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	int	i;
	int	len;
	int	min;
	int	max;
	int	pivot;

	len = stack_len(*stack_b);
	if (len == 2)
	{
		return (stack_b_len_two(stack_a, stack_b, pivot_list, sort_tool));
		// push_a(stack_a, stack_b, sort_tool.output_flag);
		// push_a(stack_a, stack_b, sort_tool.output_flag);
		// rotate_a(stack_a, sort_tool.output_flag);
		// rotate_a(stack_a, sort_tool.output_flag);
		// delete_min_pivot(pivot_list);
		// return (1);
	}
	else if (len < 4)
	{
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
		{
			if ((*stack_b)->next->data >= pivot)
				push_a(stack_a, stack_b, sort_tool.output_flag);
			else
				rotate_b(stack_b, sort_tool.output_flag);
		}
		return (0);
	}
}

void	first_partition(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list, t_sort_tool sort_tool)
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

void	partition_to_b(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list, t_sort_tool sort_tool)
{
	int	i;
	int	max;
	int	pivot;
	int	count;
	int	min;
	int	len;

	min = stack_min_limit(*stack_a, sort_tool.all_min, pivot_list);
	len = stack_len_limit(*stack_a, sort_tool.all_min, pivot_list);
	max = stack_max(*stack_a);
	if (sort_tool.sorted_list == NULL)
		pivot = find_pivot(*stack_a, min, max, len);
	else
		pivot = find_pivot_by_sorted(min, len, sort_tool.sorted_list);
	add_pivot(pivot_list, pivot);
	count = 0;
	i = -1;
	while (++i < len)
	{
		if ((*stack_a)->next->data < pivot)
			push_b(stack_a, stack_b, sort_tool.output_flag);
		else
		{
			count++;
			rotate_a(stack_a, sort_tool.output_flag);
		}
	}
	i = -1;
	while (++i < count)
		reverse_rotate_a(stack_a, sort_tool.output_flag);
}

void	partition_a(t_bi_list **stack_a, t_bi_list **stack_b, t_sort_tool sort_tool, t_pivot_list **pivot_list)
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

void	quick_sort(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag, int *sorted_list)
{
	int				top_flag;
	t_pivot_list	*pivot_list;
	t_sort_tool		sort_tool;

	top_flag = 0;
	sort_tool = init_sort_tool(stack_min(*stack_a), output_flag, sorted_list);
	pivot_list = (t_pivot_list *)malloc(sizeof(t_pivot_list));
	if (!pivot_list)
		exit(1);
	init_pivot_list(&pivot_list, sort_tool.all_min);
	while (sorted_check(*stack_a) == 1 || (*stack_b)->next != NULL)
	{
		if (top_flag == 1 && (*stack_a)->next->data == sort_tool.all_min && (*stack_b)->next != NULL)
			return ;
		if ((*stack_b)->next != NULL)
		{
			if (sorted_check(*stack_b) == 1)
			{
				if (stack_b_not_sorted(stack_a, stack_b, &pivot_list, sort_tool) == 1)
					top_flag = 1;
			}
			else
			{
				while ((*stack_b)->next != NULL)
				{
					if ((*stack_b)->next->data == pivot_list->pivot[pivot_list->len - 1])
						delete_min_pivot(&pivot_list);
					push_a(stack_a, stack_b, sort_tool.output_flag);
					rotate_a(stack_a, sort_tool.output_flag);
					top_flag = 1;
				}
			}
		}
		else
		{
			if (top_flag == 0)
				first_partition(stack_a, stack_b, &pivot_list, sort_tool);
			else
				partition_a(stack_a, stack_b, sort_tool, &pivot_list);
		}
	}
	free(pivot_list->pivot);
	free(pivot_list);
}
