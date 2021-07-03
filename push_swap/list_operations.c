/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:34:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 21:26:35 by hkubo            ###   ########.fr       */
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
		}
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_bi_list *stack_b)
{
	int	tmp;
	if (stack_b && stack_b->next)
	{
		tmp = stack_b->data;
		stack_b->data = stack_b->next->data;
		stack_b->next->data = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_ab(t_bi_list **stack_a, t_bi_list **stack_b)
{
	swap_a(*stack_a);
	swap_b(*stack_b);
	write(1, "ss\n", 3);
}

void	push_a(t_bi_list **stack_a, t_bi_list **stack_b)
{
	t_bi_list *top;

	top = (t_bi_list *)malloc(sizeof(t_bi_list));
	top->data = (*stack_b)->data;
	top->prev = NULL;
	top->next = (*stack_a);
	(*stack_a)->prev = top;
	(*stack_a) = top;
	top_del(stack_b);
	show_list(*stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_bi_list **stack_a, t_bi_list **stack_b)
{
	t_bi_list *top;

	top = (t_bi_list *)malloc(sizeof(t_bi_list));
	top->data = (*stack_a)->data;
	top->prev = NULL;
	top->next = (*stack_b);
	(*stack_b)->prev = top;
	(*stack_b) = top;
	top_del(stack_a);
	show_list(*stack_b);
	write(1, "pb\n", 3);
}
