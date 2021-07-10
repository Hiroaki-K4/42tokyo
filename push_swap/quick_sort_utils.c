/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:09:38 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/10 22:07:10 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_bi_list *stack, int min, int max, int len)
{
	int	middle;

	middle = len / 2;
	while (middle > 0)
	{
		stack = stack->next;
		middle--;
	}
	while (stack->next != NULL)
	{
		if (stack->next->data != min && stack->next->data != max)
			return (stack->next->data);
		if (stack->next->data == min ||stack->next->data == max)
			stack = stack->prev;
		else if (stack->prev->data == min ||stack->prev->data == max)
			stack = stack->next;
	}
	if (stack->data != min && stack->data != max)
		return (stack->data);
	return (0);
}

int	sorted_check(t_bi_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
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

int	stack_len_limit(t_bi_list *stack, int all_min)
{
	int	len;

	len = 0;
	while (stack->next != NULL)
	{
		if (stack->next->data == all_min)
			return (len);
		stack = stack->next;
		len++;
	}
	return (len);
}
