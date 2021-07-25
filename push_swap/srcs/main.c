/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/26 08:30:43 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sorted_list(t_bi_list *stack, int **sorted_list)
{
	int	i;
	int	len;

	len = stack_len(stack);
	if (!(*sorted_list = (int *)malloc(sizeof(int) * (len))))
		exit(1);
	i = 0;
	while (stack->next != NULL)
	{
		(*sorted_list)[i] = stack->next->data;
		stack = stack->next;
		i++;
	}
}

void	switch_by_args_num(int argc, char *argv[], t_bi_list **stack_a, t_bi_list **stack_b)
{
	int	i;
	int	*sorted_list;
	t_bi_list	*stack_tmp;

	if (argc <= 2)
		return ;
	else if (sorted_check((*stack_a)->next) == 0)
		return ;
	else if (argc == 3)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
			swap_a(*stack_a, 1);
	}
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc < 7)
		under_six(stack_a, stack_b, argc);
	else
	{
		stack_tmp = (t_bi_list *)malloc(sizeof(t_bi_list));
		stack_init(&stack_tmp);
		i = 1;
		while (i < argc)
		{
			add_stack(&stack_tmp, ft_atoi(argv[i]));
			i++;
		}
		quick_sort(&stack_tmp, stack_b, 0, NULL);
		make_sorted_list(stack_tmp, &sorted_list);
		quick_sort(stack_a, stack_b, 1, sorted_list);
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	int			num;
	t_bi_list	*stack_a;
	t_bi_list	*stack_b;

	stack_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_a)
		return (-1);
	stack_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_b)
		return (-1);
	stack_init(&stack_a);
	stack_init(&stack_b);
	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) == -1)
			error_process();
		num = ft_atoi(argv[i]);
		add_stack(&stack_a, num);
		i++;
	}
	if (duplicate_check(argc, argv) == 1)
		error_process();
	switch_by_args_num(argc, argv, &stack_a, &stack_b);
	// free(stack_a);
	// free(stack_b);
	// show_list(stack_a);
	return (0);
}
