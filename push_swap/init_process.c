/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:31:03 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 21:12:03 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_bi_list **stack_a, t_bi_list **stack_b)
{
	(*stack_a)->prev = NULL;
	(*stack_a)->next = NULL;
	(*stack_a)->data = 0;
	(*stack_b)->prev = NULL;
	(*stack_b)->next = NULL;
	(*stack_b)->data = 0;
}
