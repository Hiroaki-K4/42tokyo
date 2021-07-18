/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:50:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/18 21:10:48 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_b_not_sorted(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list)
{
	int	i;
	int	len;
	int	min;
	int	max;
	int	pivot;

	// write(1, "stack_b_not_sorted\n", 19);
	len = stack_len(*stack_b);
	if (len == 2)
	{
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		rotate_a(stack_a);
		delete_min_pivot(pivot_list);
		return (1);
	}
	else if (len < 5)
	{
		while (len > 0)
		{
			min = stack_min(*stack_b);
			if ((*stack_b)->next->data == min)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				len--;
			}
			else
				rotate_b(stack_b);
		}
		delete_min_pivot(pivot_list);
		return (1);
	}
	else
	{
		min = stack_min(*stack_b);
		max = stack_max(*stack_b);
		pivot = find_pivot(*stack_b, min, max, len);
		add_pivot(pivot_list, pivot);
		i = 0;
		while (i < len)
		{
			if ((*stack_b)->next->data > pivot)
				push_a(stack_a, stack_b);
			else
				rotate_b(stack_b);
			i++;
		}
		return (0);
	}
}

void	first_partition(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list)
{
	int	i;
	int	min;
	int	max;
	int	len;
	int pivot;

	// write(1, "first_partition\n", 16);
	min = stack_min(*stack_a);
	max = stack_max(*stack_a);
	len = stack_len(*stack_a);
	pivot = find_pivot(*stack_a, min, max, len);
	i = 0;
	while (i < len)
	{
		if ((*stack_a)->next->data < pivot)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		i++;
	}
	add_pivot(pivot_list, pivot);
}

// void	partition_to_b(t_bi_list **stack_a, t_bi_list **stack_b, int min, int len)
// {
// 	int	i;
// 	int	max;
// 	int	pivot;
// 	int	count;

// 	// write(1, "partition_to_b\n", 15);
// 	max = stack_max(*stack_a);
// 	pivot = find_pivot(*stack_a, min, max, len);
// 	count = 0;
// 	i = 0;
// 	while (i < len)
// 	{
// 		if ((*stack_a)->next->data < pivot)
// 			push_b(stack_a, stack_b);
// 		else
// 		{	count++;
// 			rotate_a(stack_a);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < count)
// 	{
// 		reverse_rotate_a(stack_a);
// 		i++;
// 	}
// }

void	partition_to_b(t_bi_list **stack_a, t_bi_list **stack_b, int min, int len, t_pivot_list **pivot_list)
{
	int	i;
	int	max;
	int	pivot;
	int	count;

	while ((*stack_a)->next->data != (*pivot_list)->pivot[(*pivot_list)->len - 1])
		push_b(stack_a, stack_b);
}

void	partition(t_bi_list **stack_a, t_bi_list **stack_b, int all_min, t_pivot_list **pivot_list)
{
	int	min;
	int	len;

	// write(1, "partition\n", 10);
	// show_list(*stack_a);
	min = stack_min_limit(*stack_a, all_min, pivot_list);
	len = stack_len_limit(*stack_a, all_min, pivot_list);
	if (len == 0 && (*stack_a)->next->data != all_min)
	{
		rotate_a(stack_a);
		delete_min_pivot(pivot_list);
	}
	else if (len == 1)
		rotate_a(stack_a);
	else if (len == 2)
	{
		if ((*stack_a)->next->data == min)
		{
			rotate_a(stack_a);
			rotate_a(stack_a);
		}
		else
		{
			swap_a(*stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
		}
	}
	else if (len > 2)
		partition_to_b(stack_a, stack_b, min, len, pivot_list);
}

void	quick_sort(t_bi_list **stack_a, t_bi_list **stack_b)
{
	int	i;
	int top_flag;
	int all_min;
	t_pivot_list	*pivot_list;

	top_flag = 0;
	all_min = stack_min(*stack_a);
	pivot_list = (t_pivot_list *)malloc(sizeof(t_pivot_list));
	init_pivot_list(&pivot_list, all_min);
	while (sorted_check(*stack_a) == 1 || (*stack_b)->next != NULL)
	{
		if (top_flag == 1 && (*stack_a)->next->data == all_min && (*stack_b)->next != NULL)
			return ;
		if ((*stack_b)->next != NULL)
		{
			if (sorted_check(*stack_b) == 1)
			{
				if (stack_b_not_sorted(stack_a, stack_b, &pivot_list) == 1)
					top_flag = 1;
			}
			else
			{
				while ((*stack_b)->next != NULL)
				{
					push_a(stack_a, stack_b);
					rotate_a(stack_a);
					top_flag = 1;
				}
			}
		}
		else
		{
			if (top_flag == 0)
				first_partition(stack_a, stack_b, &pivot_list);
			else
				partition(stack_a, stack_b, all_min, &pivot_list);
		}
		i = 0;
		while (pivot_list->len - i > 0)
		{
			// printf("pivot%d: %d\n", i+1, pivot_list->pivot[i]);
			i++;
		}
	}
}
