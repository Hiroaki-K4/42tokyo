/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:30:56 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 22:45:21 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_bi_list **stack_a)
{
	t_bi_list *last;
	t_bi_list *tmp;

	if ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->next->next != NULL)
		{
			last = last_stack(*stack_a);
			last->prev->next = NULL;
			tmp = (*stack_a)->next;
			last->next = tmp;
			tmp->prev = last;
			last->prev = *stack_a;
			(*stack_a)->next = last; 
			write(1, "rra\n", 4);
		}
	}
}
