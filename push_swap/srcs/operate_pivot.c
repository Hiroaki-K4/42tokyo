/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:02:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/25 14:12:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_bi_list *stack, int min, int max, int len)
{
	while (stack->next != NULL && len > 0)
	{
		if (stack->next->data != min && stack->next->data != max)
			return (stack->next->data);
		stack = stack->next;
		len--;
	}
	if (stack->data != min && stack->data != max)
		return (stack->data);
	return (0);
}

// int	find_pivot(int arg1, int arg2, int arg3)
// {
// 	int	pivot;
// 	int	min;
// 	int	max;

// 	min = arg1;
// 	if (min > arg2)
// 		min = arg2;
// 	if (min > arg3)
// 		min = arg3;
// 	max = arg1;
// 	if (max < arg2)
// 		max = arg2;
// 	if (max < arg3)
// 		max = arg3;
// 	if (arg1 != min && arg1 != max)
// 		pivot = arg1;
// 	else if (arg2 != min && arg2 != max)
// 		pivot = arg2;
// 	else
// 		pivot = arg3;
// 	return (pivot);
// }

int	init_pivot_list(t_pivot_list **pivot_list, int all_min)
{
	(*pivot_list)->len = 0;
	if (!((*pivot_list)->pivot = (int *)malloc(sizeof(int) * 1)))
		return (-1);
	(*pivot_list)->pivot[0] = all_min;
	return (0);
}

int	add_pivot(t_pivot_list **pivot_list, int pivot)
{
	int	i;
	int *new_pivot_list;

	// printf("add_pivot: %d\n", pivot);
	if ((*pivot_list)->len == 0)
	{
		free((*pivot_list)->pivot);
		if (!((*pivot_list)->pivot = (int *)malloc(sizeof(int) * 1)))
			return (-1);
		(*pivot_list)->len++;
		(*pivot_list)->pivot[0] = pivot;
	}
	else
	{
		if (!(new_pivot_list = (int *)malloc(sizeof(int) * ((*pivot_list)->len + 1))))
			return (-1);
		i = 0;
		while ((*pivot_list)->len - i > 0)
		{
			new_pivot_list[i] = (*pivot_list)->pivot[i];
			i++;
		}
		free((*pivot_list)->pivot);
		new_pivot_list[i] = pivot;
		(*pivot_list)->pivot = new_pivot_list;
		(*pivot_list)->len++;
	}
	return (0);
}

int	delete_min_pivot(t_pivot_list **pivot_list)
{
	int	i;
	int *new_pivot_list;

	if (!(new_pivot_list = (int *)malloc(sizeof(int) * ((*pivot_list)->len - 1))))
		return (-1);
	i = 0;
	while ((*pivot_list)->len - 1 - i > 0)
	{
		new_pivot_list[i] = (*pivot_list)->pivot[i];
		i++;
	}
	free((*pivot_list)->pivot);
	(*pivot_list)->pivot = new_pivot_list;
	(*pivot_list)->len--;
	return (0);
}