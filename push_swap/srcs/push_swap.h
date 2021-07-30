/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:32:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/29 23:17:30 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_bi_list
{
	int					data;
	struct s_bi_list	*prev;
	struct s_bi_list	*next;
}	t_bi_list;

typedef struct s_pivot_list
{
	int	len;
	int	*pivot;
}	t_pivot_list;

void		error_process();
void		push_a(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag);
void		push_b(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag);
void		swap_a(t_bi_list *stack_a, int output_flag);
void		swap_b(t_bi_list *stack_b, int output_flag);
void		swap_ab(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag);
void		top_del(t_bi_list **list);
void		show_list(t_bi_list *list);
void		stack_init(t_bi_list **stack);
void		rotate_a(t_bi_list **stack_a, int output_flag);
void		rotate_b(t_bi_list **stack_b, int output_flag);
void		rotate_ab(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag);
void		reverse_rotate_a(t_bi_list **stack_a, int output_flag);
void		reverse_rotate_b(t_bi_list **stack_b, int output_flag);
void		reverse_rotate_ab(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag);
void		under_six(t_bi_list **stack_a, t_bi_list **stack_b, int argc);
void		sort_three(t_bi_list **stack);
void		switch_by_args_num(int argc, char *argv[], t_bi_list **stack_a, t_bi_list **stack_b);
void		partition(t_bi_list **stack_a, t_bi_list **stack_b, int all_min, t_pivot_list **pivot_list, int output_flag, int *sorted_list);
void		quick_sort(t_bi_list **stack_a, t_bi_list **stack_b, int output_flag, int *sorted_list);
void		first_partition(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list, int output_flag, int *sorted_list);
int			delete_min_pivot(t_pivot_list **pivot_list);
int			init_pivot_list(t_pivot_list **pivot_list, int all_min);
int			digit_check(const char *arg);
int			duplicate_check(int argc, char *argv[]);
int			sorted_check(t_bi_list *stack);
int			stack_min(t_bi_list *stack);
int			stack_min_limit(t_bi_list *stack, int all_min, t_pivot_list **pivot_list);
int			add_stack(t_bi_list **stack, int num);
int			stack_max(t_bi_list *stack);
int			stack_max_limit(t_bi_list *stack, int len);
int			stack_len(t_bi_list *stack);
int			stack_len_limit(t_bi_list *stack, int all_min, t_pivot_list **pivot_list);
int			find_pivot(t_bi_list *stack, int min, int max, int len);
// int			find_pivot(int arg1, int arg2, int arg3);
int			find_pivot_by_sorted(int min, int len, int *sorted_list);
int			stack_b_not_sorted(t_bi_list **stack_a, t_bi_list **stack_b, t_pivot_list **pivot_list, int output_flag, int *sorted_list);
int			add_pivot(t_pivot_list **pivot_list, int pivot);
t_bi_list	*last_stack(t_bi_list *stack);

#endif
