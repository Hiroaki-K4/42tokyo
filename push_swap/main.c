/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/04 14:12:07 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	branch_process(int argc, t_bi_list **stack_a, t_bi_list **stack_b)
// {
// 	if (argc == 2)
// 		return (0);
// 	else if (argc == 3)
// 	{
		
// 	}
// 	else if (argc )
// }

int	main(int argc, char *argv[])
{
	int i;
	int num;
	t_bi_list *stack_a;
	t_bi_list *stack_b;

	stack_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_a)
		return (-1);
	stack_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!stack_b)
		return (-1);
	stack_init(&stack_a, &stack_b);
	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) == -1)
			error_process();
		num = ft_atoi(argv[i]);
		add_stack(&stack_a, num);
		// add_stack(&stack_b, num);
		i++;
	}
	if (duplicate_check(argc, argv) == 1)
		error_process();
	// branch_process(argc, &stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// swap_b(stack_a);
	// swap_b(stack_b);
	// swap_ab(&stack_a, &stack_b);
	// rotate_a(&stack_a);
	// rotate_b(&stack_b);
	// rotate_ab(&stack_a, &stack_b);
	// reverse_rotate_a(&stack_a);
	// reverse_rotate_b(&stack_b);
	// reverse_rotate_ab(&stack_a, &stack_b);
	show_list(stack_a);
	show_list(stack_b);
	return (0);
}
