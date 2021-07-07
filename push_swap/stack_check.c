/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:12:15 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/07 23:12:46 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_bi_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->data > stack_a->next->data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

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
