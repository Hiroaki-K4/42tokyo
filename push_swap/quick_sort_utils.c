/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:09:38 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/11 18:22:35 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_bi_list *stack, int min, int max, int len)
{
	// int	middle;

	// middle = len / 2;
	// while (middle > 0)
	// {
		// stack = stack->next;
		// middle--;
	// }
	while (stack->next != NULL && len > 0)
	{
		if (stack->next->data != min && stack->next->data != max)
			return (stack->next->data);
		// if (stack->next->next->data == min || stack->next->next->data == max)
		// 	stack = stack->prev;
		// else if (stack->data == min || stack->data == max)
		stack = stack->next;
		len--;
	}
	if (stack->data != min && stack->data != max)
		return (stack->data);
	return (0);
}

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
