/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:02:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/17 22:30:38 by hkubo            ###   ########.fr       */
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
		write(1, "ok3\n", 4);
		if (!(*pivot_list = (int *)malloc(sizeof(int) * 8)))
			return (-1);
		write(1, "ok4\n", 4);
		*pivot_list[0] = pivot;
		write(1, "ok5\n", 4);
		*pivot_list[1] = pivot;
		write(1, "ok6\n", 4);
	}
	else
	{
		len = 0;
		while (*pivot_list[len])
			len++;
		if (!(new_pivot_list = (int *)malloc(sizeof(int) * (len + 2))))
			return (-1);
		len = 0;
		while (*pivot_list[len])
		{
			new_pivot_list[len] = *pivot_list[len];
			len++;
		}
		free(*pivot_list);
		new_pivot_list[len++] = pivot;
		new_pivot_list[len] = '\0';
		*pivot_list = new_pivot_list;
	}
	return (0);
}
