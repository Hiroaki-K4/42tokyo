/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:02:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 17:23:29 by hkubo            ###   ########.fr       */
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
			break ;
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

t_pivot_list	*init_pivot_list(int all_min)
{
	t_pivot_list	*pivot_list;

	pivot_list = (t_pivot_list *)malloc(sizeof(t_pivot_list));
	if (!pivot_list)
		exit(1);
	pivot_list->len = 0;
	pivot_list->pivot = (int *)malloc(sizeof(int) * 1);
	if (!pivot_list->pivot)
		exit(1);
	pivot_list->pivot[0] = all_min;
	return (pivot_list);
}

void	add_pivot(t_pivot_list **pivot_list, int pivot)
{
	int	i;
	int	*new_pivot_list;

	if ((*pivot_list)->len == 0)
	{
		free((*pivot_list)->pivot);
		(*pivot_list)->pivot = (int *)malloc(sizeof(int) * 1);
		if (!(*pivot_list)->pivot)
			exit(1);
		(*pivot_list)->len++;
		(*pivot_list)->pivot[0] = pivot;
	}
	else
	{
		new_pivot_list = (int *)malloc(sizeof(int) * ((*pivot_list)->len + 1));
		if (!new_pivot_list)
			exit(1);
		i = -1;
		while ((*pivot_list)->len - (++i) > 0)
			new_pivot_list[i] = (*pivot_list)->pivot[i];
		free((*pivot_list)->pivot);
		new_pivot_list[i] = pivot;
		(*pivot_list)->pivot = new_pivot_list;
		(*pivot_list)->len++;
	}
}

int	delete_min_pivot(t_pivot_list **pivot_list)
{
	int	i;
	int	*new_pivot_list;

	new_pivot_list = (int *)malloc(sizeof(int) * ((*pivot_list)->len - 1));
	if (!new_pivot_list)
		exit(1);
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
	return (0);
}
