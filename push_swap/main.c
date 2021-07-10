/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/10 18:30:14 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_bi_list **stack_a, t_bi_list **stack_b)
{
	int	i;
	int	len;
	int	min;
	int	max;
	int	pivot;
	int top_flag;
	int all_min;
	int count;
	t_bi_list *tmp;

	top_flag = 0;
	all_min = stack_min(*stack_a);
	while (sorted_check(*stack_a) == 1 || (*stack_b)->next != NULL)
	{
		if (top_flag == 1 && (*stack_a)->next->data == all_min && (*stack_b)->next != NULL)
			return ;
		if ((*stack_b)->next != NULL)
		{
			if (sorted_check(*stack_b) == 1)
			{
				len = stack_len(*stack_b);
				if (len < 6)
				{
					stack_init(&tmp);
					branch_process(len + 1, stack_b, &tmp);
					i = 0;
					while (i < len)
					{
						push_a(stack_a, stack_b);
						rotate_a(stack_a);
						top_flag = 1;
						i++;
					}
					printf("a1\n");
					show_list(*stack_a);
					printf("b1\n");
					show_list(*stack_b);
				}
				else
				{
					min = stack_min(*stack_b);
					max = stack_max(*stack_b);
					pivot = find_pivot(*stack_b, min, max, len);
					i = 0;
					while (i < len)
					{
						if ((*stack_b)->next->data > pivot)
							push_a(stack_a, stack_b);
						else
							rotate_b(stack_b);
						i++;
					}
					printf("a2\n");
					show_list(*stack_a);
					printf("b2\n");
					show_list(*stack_b);
				}
			}
			else
			{
				while ((*stack_b)->next != NULL)
				{
					push_a(stack_a, stack_b);
					rotate_a(stack_a);
				}
			}
			// printf("pivot: %d b_min: %d b_max: %d b_len: %d\n", pivot, min, max, len);
			// printf("a\n");
			// show_list(*stack_a);
			// printf("b\n");
			// show_list(*stack_b);
		}
		else
		{
			if (top_flag == 0)
			{
				min = stack_min(*stack_a);
				max = stack_max(*stack_a);
				len = stack_len(*stack_a);
				pivot = find_pivot(*stack_a, min, max, len);
				i = 0;
				while (i < len)
				{
					if ((*stack_a)->next->data < pivot)
						push_b(stack_a, stack_b);
					else
						rotate_a(stack_a);
					i++;
				}
				printf("a3\n");
				show_list(*stack_a);
				printf("b3\n");
				show_list(*stack_b);
			}
			else
			{
				min = stack_min_limit(*stack_a, all_min);
				max = stack_max(*stack_a);
				len = stack_len_limit(*stack_a, all_min);
				if (len == 1)
					rotate_a(stack_a);
				else if (len == 2)
				{
					if ((*stack_a)->next->data == min)
					{
						rotate_a(stack_a);
						rotate_a(stack_a);
					}
					else
					{
						push_b(stack_a, stack_b);
						rotate_a(stack_a);
						push_a(stack_a, stack_b);
						rotate_a(stack_a);
					}
				}
				else
				{
					pivot = find_pivot(*stack_a, min, max, len);
					count = 0;
					i = 0;
					while (i < len)
					{
						if ((*stack_a)->next->data < pivot)
							push_b(stack_a, stack_b);
						else
						{	count++;
							rotate_a(stack_a);
						}
						i++;
					}
					i = 0;
					while (i < count)
					{
						reverse_rotate_a(stack_a);
						i++;
					}
				}
				printf("a4\n");
				show_list(*stack_a);
				printf("b4\n");
				show_list(*stack_b);
			}
		}
	}
}

void	branch_process(int argc, t_bi_list **stack_a, t_bi_list **stack_b)
{
	if (argc <= 2)
		return ;
	else if (sorted_check((*stack_a)->next) == 0)
		return ;
	else if (argc == 3)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
			swap_a(*stack_a);
	}
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc < 7)
		under_six(stack_a, stack_b, argc);
	else
		quick_sort(stack_a, stack_b);
	printf("branch\n");
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
	branch_process(argc, &stack_a, &stack_b);
	printf("final\n"));
	return (0);
}
