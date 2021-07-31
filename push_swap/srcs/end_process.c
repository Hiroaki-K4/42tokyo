/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:30:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 17:48:27 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_process(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_stack(t_bi_list **stack)
{
	t_bi_list	*next;

	next = NULL;
	while ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		(*stack) = next;
	}
	free(*stack);
}

void	free_pivot_list(t_pivot_list *pivot_list)
{
	free(pivot_list->pivot);
	free(pivot_list);
}
