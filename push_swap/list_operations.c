/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:34:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 18:35:03 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
