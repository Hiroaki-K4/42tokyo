/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:02:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/17 22:15:41 by hkubo            ###   ########.fr       */
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

int	add_pivot(int **pivot_list, int pivot)
{
	int	len;
	int *new_pivot_list;

	if (*pivot_list == NULL)
	{
		if (!(*pivot_list = (int *)malloc(sizeof(int) * 2)))
			return (-1);
		*pivot_list[0] = pivot;
		*pivot_list[1] = '\0';
	}
	else
	{
		len = 0;
		while (pivot_list[len])
			len++;
		if (!(new_pivot_list = (int *)malloc(sizeof(int) * (len + 2))))
			return (-1);
		len = 0;
		while (pivot_list[len])
		{
			new_pivot_list[len] = pivot_list[len];
			len++;
		}
		free(*pivot_list);
		new_pivot_list[len++] = pivot;
		new_pivot_list[len] = '\0';
		*pivot_list = new_pivot_list;
	}
	return (0);
}
