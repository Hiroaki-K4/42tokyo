/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:04:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/30 23:08:05 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_bi_list **stack_a, int output_flag)
{
	t_bi_list	*last;
	t_bi_list	*tmp;

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
			if (output_flag == 1)
				write(1, "ra\n", 3);
		}
	}
}

void	rotate_b(t_bi_list **stack_b, int output_flag)
{
	t_bi_list	*last;
	t_bi_list	*tmp;

	if ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->next->next != NULL)
		{
			(*stack_b)->next->next->prev = *stack_b;
			tmp = (*stack_b)->next->next;
			last = last_stack(*stack_b);
			(*stack_b)->next->prev = last;
			last->next = (*stack_b)->next;
			(*stack_b)->next->next = NULL;
			(*stack_b)->next = tmp;
			if (output_flag == 1)
				write(1, "rb\n", 3);
		}
	}
}

// void	rotate_ab(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag)
// {
// 	rotate_a(stack_a, output_flag);
// 	rotate_b(stack_b, output_flag);
// 	if (output_flag == 1)
// 		write(1, "rr\n", 3);
// }
