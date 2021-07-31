/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:31:03 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/31 17:45:36 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_bi_list **stack)
{
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->data = 0;
}

t_sort_tool	init_list(t_bi_list *stack, int output_flag, int *sorted_list,
	t_pivot_list **pivot_list)
{
	t_sort_tool	sort_tool;

	sort_tool.all_min = stack_min(stack);
	sort_tool.output_flag = output_flag;
	sort_tool.sorted_list = sorted_list;
	*pivot_list = init_pivot_list(stack_min(stack));
	return (sort_tool);
}
