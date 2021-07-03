/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:34:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 20:22:31 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_bi_list *stack_a)
{
	int	tmp;
	if (stack_a && stack_a->next)
	{
		tmp = stack_a->data;
		stack_a->data = stack_a->next->data;
		stack_a->next->data = tmp;
	}
	write(1, "sa\n", 3);
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
