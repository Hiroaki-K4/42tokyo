/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:09:38 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/10 16:10:01 by hkubo            ###   ########.fr       */
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
		stack = stack->next;
	}
	if (stack->data != min && stack->data != max)
		return (stack->data);
	return (0);
}
