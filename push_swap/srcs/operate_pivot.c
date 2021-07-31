/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:02:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 13:52:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot_by_sorted(int min, int len, int *sorted_list)
{
	int	i;
	int	pivot;

	i = 1;
	while (i < sorted_list[0] + 1)
	{
		if (sorted_list[i] == min)
			break;
		i++;
	}
	pivot = sorted_list[i + len / 2];
	return (pivot);
}

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
	(*pivot_list)->pivot = NULL;
	(*pivot_list)->pivot = new_pivot_list;
	(*pivot_list)->len--;
	exit (0);
}