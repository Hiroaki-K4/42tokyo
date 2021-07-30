/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:30:34 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/30 23:21:50 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_process()
{
	write(1, "Error\n", 6);
	exit(0);
}

void	free_stack(t_list **stack)
{
	while ((*stack)->next != NULL)
	{
		free(*stack);
		(*stack) = (*stack)->next;
	}
}