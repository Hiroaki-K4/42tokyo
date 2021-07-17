/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:02:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/17 22:56:11 by hkubo            ###   ########.fr       */
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

void	init_pivot_list(t_pivot_list **pivot_list)
{
	(*pivot_list)->len = 0;
	(*pivot_list)->pivot = NULL;
}

int	add_pivot(t_pivot_list **pivot_list, int pivot)
{
	int	i;
	int *new_pivot_list;

	if ((*pivot_list)->len == 0)
	{
		write(1, "ok3\n", 4);
		if (!((*pivot_list)->pivot = (int *)malloc(sizeof(int) * 1)))
			return (-1);
		write(1, "ok4\n", 4);
		(*pivot_list)->len++;
		(*pivot_list)->pivot = pivot;
		write(1, "ok5\n", 4);
		write(1, "ok6\n", 4);
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
		new_pivot_list[i++] = pivot;
		new_pivot_list[i] = '\0';
		(*pivot_list)->pivot = new_pivot_list;
	}
	return (0);
}
