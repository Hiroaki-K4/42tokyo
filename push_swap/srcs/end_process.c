/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:30:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 14:30:04 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_process()
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