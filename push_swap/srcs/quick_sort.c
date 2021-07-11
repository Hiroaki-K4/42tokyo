/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:50:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/11 22:53:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_b_not_sorted(t_bi_list **stack_a, t_bi_list **stack_b)
{
	int	i;
	int	len;
	int	min;
	int	max;
	int	pivot;

	write(1, "stack_b_not_sorted\n", 19);
	len = stack_len(*stack_b);
	if (len == 2)
	{
		// write(1, "branch1.1\n", 10);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		rotate_a(stack_a);
		// show_list(*stack_a);
		// write(1, "~~~~~\n", 6);
		// show_list(*stack_b);
		return (1);
	}
	else if (len < 30)
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
		return (1);
	}
	else
	{
		min = stack_min(*stack_b);
		max = stack_max(*stack_b);
		pivot = find_pivot(*stack_b, min, max, len);
		i = 0;
		while (i < len)
		{
			if ((*stack_b)->next->data > pivot)
				push_a(stack_a, stack_b);
			else
				rotate_b(stack_b);
			i++;
		}
		// show_list(*stack_a);
		// write(1, "~~~~~\n", 6);
		// show_list(*stack_b);
		return (0);
	}
}

void	first_partition(t_bi_list **stack_a, t_bi_list **stack_b)
{
	int	i;
	int	min;
	int	max;
	int	len;
	int pivot;

	write(1, "first_partition\n", 16);
	min = stack_min(*stack_a);
	max = stack_max(*stack_a);
	len = stack_len(*stack_a);
	pivot = find_pivot(*stack_a, min, max, len);
	i = 0;
	while (i < len)
	{
		if ((*stack_a)->next->data <= pivot)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		i++;
	}
	// show_list(*stack_a);
	// write(1, "~~~~~\n", 6);
	// show_list(*stack_b);
}

void	partition_to_b(t_bi_list **stack_a, t_bi_list **stack_b, int min, int len)
{
	int	i;
	int	max;
	int	pivot;
	int	count;

	write(1, "partition_to_b\n", 15);
	max = stack_max(*stack_a);
	pivot = find_pivot(*stack_a, min, max, len);
	count = 0;
	i = 0;
	while (i < len)
	{
		if ((*stack_a)->next->data <= pivot)
			push_b(stack_a, stack_b);
		else
		{	count++;
			rotate_a(stack_a);
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		reverse_rotate_a(stack_a);
		i++;
	}
}

void	partition(t_bi_list **stack_a, t_bi_list **stack_b, int all_min)
{
	int	min;
	int	len;

	write(1, "partition\n", 10);
	min = stack_min_limit(*stack_a, all_min);
	len = stack_len_limit(*stack_a, all_min);
	// show_list(*stack_a);
	if (len == 1)
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
			push_b(stack_a, stack_b);
			rotate_a(stack_a);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
	}
	else if (len > 2)
		partition_to_b(stack_a, stack_b, min, len);
	// show_list(*stack_a);
	// write(1, "~~~~~\n", 6);
	// show_list(*stack_b);
}