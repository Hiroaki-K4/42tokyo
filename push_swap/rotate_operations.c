/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:04:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 22:18:43 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_bi_list **stack_a)
{
	t_bi_list *last;
	t_bi_list *tmp;

	if ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->next->next != NULL)
		{
			(*stack_a)->next->next->prev = *stack_a;
			tmp = (*stack_a)->next->next;
			last = last_stack(*stack_a);
			(*stack_a)->next->prev = last;
			last->next = (*stack_a)->next;
			(*stack_a)->next->next = NULL;
			(*stack_a)->next = tmp;
		}
	}
	printf("top: %d\n", (*stack_a)->data);
}