/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:30:56 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/25 18:04:27 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_bi_list **stack_a, int output_flag)
{
	t_bi_list	*last;
	t_bi_list	*tmp;

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
			if (output_flag == 1)
				write(1, "rra\n", 4);
		}
	}
}

void	reverse_rotate_b(t_bi_list **stack_b, int output_flag)
{
	t_bi_list	*last;
	t_bi_list	*tmp;

	if ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->next->next != NULL)
		{
			last = last_stack(*stack_b);
			last->prev->next = NULL;
			tmp = (*stack_b)->next;
			last->next = tmp;
			tmp->prev = last;
			last->prev = *stack_b;
			(*stack_b)->next = last;
			if (output_flag == 1)
				write(1, "rrb\n", 4);
		}
	}
}

void	reverse_rotate_ab(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag)
{
	reverse_rotate_a(stack_a, output_flag);
	reverse_rotate_b(stack_b, output_flag);
	if (output_flag == 1)
		write(1, "rrr\n", 4);
}
