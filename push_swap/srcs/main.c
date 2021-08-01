/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/01 15:30:36 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sorted_list(t_bi_list *stack, int **sorted_list)
{
	int	i;
	int	len;

	len = stack_len(stack);
	*sorted_list = (int *)malloc(sizeof(int) * (len + 1));
	if (!*sorted_list)
		exit(1);
	(*sorted_list)[0] = len;
	i = 1;
	while (stack->next != NULL)
	{
		(*sorted_list)[i] = stack->next->data;
		stack = stack->next;
		i++;
	}
}

void	few_args_process(int argc, t_bi_list **stack_a, t_bi_list **stack_b)
{
	if (argc <= 2)
		return ;
	else if (sorted_check(*stack_a) == 0)
		return ;
	else if (argc == 3)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
			swap_a(*stack_a, 1);
	}
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc < 7)
		args_under_six(stack_a, stack_b, argc);
}

int	add_args(int argc, char *argv[], t_bi_list **stack)
{
	int	i;
	int	j;
	int	args_count;
	char **arg_split;

	args_count = 0;
	i = 0;
	while (++i < argc)
	{
		arg_split = ft_split(argv[i], ' ');
		if (!arg_split)
			exit(1);
		j = 0;
		while (arg_split[j])
		{
			if (digit_check(arg_split[j]) == -1)
				error_process();
			add_stack(stack, ft_atoi(arg_split[j]));
			free(arg_split[j]);
			j++;
		}
		free(arg_split);
		args_count += j;
	}
	return (args_count);
}

void	switch_by_args_num(int argc, char *argv[], int args_count, t_bi_list **stack_a,
	t_bi_list **stack_b)
{
	int			*sorted_list;
	t_bi_list	*stack_tmp;

	if (args_count + 1 < 7)
		few_args_process(args_count + 1, stack_a, stack_b);
	else
	{
		stack_tmp = (t_bi_list *)malloc(sizeof(t_bi_list));
		if (!stack_tmp)
			exit(1);
		stack_init(&stack_tmp);
		add_args(argc, argv, &stack_tmp);
		quick_sort(&stack_tmp, stack_b, 0, NULL);
		make_sorted_list(stack_tmp, &sorted_list);
		free_stack(&stack_tmp);
		quick_sort(stack_a, stack_b, 1, sorted_list);
		free(sorted_list);
	}
}

int	main(int argc, char *argv[])
{
	int			args_count;
	t_bi_list	*stack_a;
	t_bi_list	*stack_b;

	stack_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_a)
		exit(1);
	stack_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_b)
		exit(1);
	stack_init(&stack_a);
	stack_init(&stack_b);	
	args_count = add_args(argc, argv, &stack_a);
	if (duplicate_check(args_count, stack_a) == 1)
		error_process();
	switch_by_args_num(argc, argv, args_count, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
