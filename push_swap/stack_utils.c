/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:00:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/04 12:01:03 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bi_list	*last_stack(t_bi_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	add_stack(t_bi_list **stack, int num)
{
	t_bi_list	*new;
	t_bi_list	*last;

	new = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!new)
		return (-1);
	new->data = num;
	last = last_stack(*stack);
	new->prev = last;
	new->next = NULL;
	last->next = new;
	return (0);
}

void	show_list(t_bi_list *list)
{
	while (list != NULL)
	{
		if (list->prev != NULL)
			printf("data: %d\n", list->data);
		list = list->next;
	}
}

void	top_del(t_bi_list **list)
{
	if ((*list)->next->next)
		(*list)->next = (*list)->next->next;
}
