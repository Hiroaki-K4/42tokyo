/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:09:38 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/18 18:33:58 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_len_limit(t_bi_list *stack, int all_min, t_pivot_list **pivot_list)
{
	int	len;

	printf("min_pivot: %d\n", (*pivot_list)->pivot[(*pivot_list)->len - 1]);
	len = 0;
	while (stack->next != NULL)
	{
		if (stack->next->data == all_min || stack->next->data >= (*pivot_list)->pivot[(*pivot_list)->len - 1]);
			return (len);
		stack = stack->next;
		len++;
	}
	return (len);
}
