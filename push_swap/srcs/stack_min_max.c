/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:12:15 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/24 12:12:17 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_bi_list *stack)
{
	int	min;

	min = stack->next->data;
	while (stack->next != NULL)
	{
		if (min > stack->next->data)
			min = stack->next->data;
		stack = stack->next;
	}
	if (min > stack->data)
		min = stack->data;
	return (min);
}

int	stack_max(t_bi_list *stack)
{
	int	max;

	max = stack->next->data;
	while (stack->next != NULL)
	{
		if (max < stack->next->data)
			max = stack->next->data;
		stack = stack->next;
	}
	if (max < stack->data)
		max = stack->data;
	return (max);
}

int	stack_min_limit(t_bi_list *stack, int all_min, t_pivot_list **pivot_list)
{
	int	min;

	// printf("min_limit: %d\n", (*pivot_list)->pivot[(*pivot_list)->len - 1]);
	min = stack->next->data;
	while (stack->next != NULL && stack->next->data != all_min)
	{
		if (stack->next->data == (*pivot_list)->pivot[(*pivot_list)->len - 1])
		{
			if (min > stack->next->data)
			{
				min = stack->next->data;
				delete_min_pivot(pivot_list);
			}
			else
				break;
		}	
		if (min > stack->next->data)
			min = stack->next->data;
		stack = stack->next;
	}
	if (min > stack->data)
		min = stack->data;
	return (min);
}
