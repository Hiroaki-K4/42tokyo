/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:34:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/04 16:46:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_bi_list *stack_a)
{
	int	tmp;

	if (stack_a && stack_a->next)
	{
		if (stack_a->next->next)
		{
			tmp = stack_a->next->data;
			stack_a->next->data = stack_a->next->next->data;
			stack_a->next->next->data = tmp;
			write(1, "sa\n", 3);
		}
	}
}

void	swap_b(t_bi_list *stack_b)
{
	int	tmp;

	if (stack_b && stack_b->next)
	{
		if (stack_b->next->next)
		{
			tmp = stack_b->next->data;
			stack_b->next->data = stack_b->next->next->data;
			stack_b->next->next->data = tmp;
			write(1, "sb\n", 3);
		}
	}
}

void	swap_ab(t_bi_list **stack_a, t_bi_list **stack_b)
{
	int	tmp;

	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		if ((*stack_a)->next->next && (*stack_b)->next->next)
		{
			tmp = (*stack_a)->next->data;
			(*stack_a)->next->data = (*stack_a)->next->next->data;
			(*stack_a)->next->next->data = tmp;
			tmp = (*stack_b)->next->data;
			(*stack_b)->next->data = (*stack_b)->next->next->data;
			(*stack_b)->next->next->data = tmp;
			write(1, "ss\n", 3);
		}
	}
}

void	push_a(t_bi_list **stack_a, t_bi_list **stack_b)
{
	t_bi_list	*top;

	if ((*stack_b)->next != NULL)
	{
		top = (t_bi_list *)malloc(sizeof(t_bi_list));
		top->data = (*stack_b)->next->data;
		top->prev = *stack_a;
		top->next = (*stack_a)->next;
		(*stack_a)->next->prev = top;
		*stack_a = top;
		top_del(stack_b);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_bi_list **stack_a, t_bi_list **stack_b)
{
	t_bi_list	*top;

	if ((*stack_a)->next != NULL)
	{
		top = (t_bi_list *)malloc(sizeof(t_bi_list));
		top->data = (*stack_a)->next->data;
		top->prev = *stack_b;
		top->next = (*stack_b)->next;
		if ((*stack_b)->next != NULL)
			(*stack_b)->next->prev = top;
		(*stack_b) = top;
		top_del(stack_a);
		write(1, "pb\n", 3);
	}
}
