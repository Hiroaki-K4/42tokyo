/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 22:28:39 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bi_list	*last_stack(t_bi_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	add_stack(t_bi_list **stack, int num)
{
	t_bi_list	*new;
	t_bi_list	*last;

	new = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!new)
		return (-1);
	new->data = num;
	last = last_stack(*stack);
	new->prev = last;
	new->next = NULL;
	last->next = new;
	return (0);
}

void	show_list(t_bi_list *list)
{
	while (list != NULL)
	{
		if (list->prev != NULL)
			printf("data: %d\n", list->data);
		list = list->next;
	}
}

void	top_del(t_bi_list **list)
{
	if ((*list)->next->next)
		(*list)->next = (*list)->next->next;
}

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
		add_stack(&stack_b, num);
		i++;
	}
	if (duplicate_check(argc, argv) == 1)
		error_process();
	// push_a(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// swap_b(stack_a);
	// swap_b(stack_b);
	// swap_ab(&stack_a, &stack_b);
	// rotate_a(&stack_a);
	// rotate_b(&stack_b);
	rotate_ab(&stack_a, &stack_b);
	show_list(stack_a);
	show_list(stack_b);
	return (0);
}
