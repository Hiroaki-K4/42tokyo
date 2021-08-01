/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:32:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/01 18:39:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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

typedef struct s_sort_tool
{
	int	all_min;
	int	output_flag;
	int	*sorted_list;
}	t_sort_tool;

void			error_process(void);
void			push_a(t_bi_list **stack_a, t_bi_list **stack_b,
					int output_flag);
void			push_b(t_bi_list **stack_a, t_bi_list **stack_b,
					int output_flag);
void			swap_a(t_bi_list *stack_a, int output_flag);
void			swap_b(t_bi_list *stack_b, int output_flag);
void			top_del(t_bi_list **list);
void			stack_init(t_bi_list **stack);
void			rotate_a(t_bi_list **stack_a, int output_flag);
void			rotate_b(t_bi_list **stack_b, int output_flag);
void			reverse_rotate_a(t_bi_list **stack_a, int output_flag);
void			reverse_rotate_b(t_bi_list **stack_b, int output_flag);
void			args_under_six(t_bi_list **stack_a, t_bi_list **stack_b,
					int argc);
void			sort_three(t_bi_list **stack);
void			quick_sort(t_bi_list **stack_a, t_bi_list **stack_b,
					int output_flag, int *sorted_list);
void			first_partition(t_bi_list **stack_a, t_bi_list **stack_b,
					t_pivot_list **pivot_list, t_sort_tool sort_tool);
void			free_stack(t_bi_list **stack);
void			add_pivot(t_pivot_list **pivot_list, int pivot);
void			arg_two_operations(t_bi_list **stack_a, t_sort_tool sort_tool,
					int min);
void			stack_b_over_three(t_bi_list **stack_a, t_bi_list **stack_b,
					int pivot, t_sort_tool sort_tool);
void			free_pivot_list(t_pivot_list *pivot_list);
int				delete_min_pivot(t_pivot_list **pivot_list);
int				digit_check(const char *arg);
int				duplicate_check(int args_count, t_bi_list *stack);
int				sorted_check(t_bi_list *stack);
int				stack_min(t_bi_list *stack);
int				stack_min_limit(t_bi_list *stack, int all_min,
					t_pivot_list **pivot_list);
int				add_stack(t_bi_list **stack, int num);
int				stack_max(t_bi_list *stack);
int				stack_max_limit(t_bi_list *stack, int len);
int				stack_len(t_bi_list *stack);
int				stack_len_limit(t_bi_list *stack, int all_min,
					t_pivot_list **pivot_list);
int				find_pivot(t_bi_list *stack, int min, int max, int len);
int				find_pivot_by_sorted(int min, int len, int *sorted_list);
int				stack_b_not_sorted(t_bi_list **stack_a, t_bi_list **stack_b,
					t_pivot_list **pivot_list, t_sort_tool sort_tool);
int				stack_b_len_two(t_bi_list **stack_a, t_bi_list **stack_b,
					t_pivot_list **pivot_list, t_sort_tool sort_tool);
int				stack_b_len_three(t_bi_list **stack_a, t_bi_list **stack_b,
					t_pivot_list **pivot_list, t_sort_tool sort_tool);
int				stack_b_not_empty(t_bi_list **stack_a, t_bi_list **stack_b,
					t_pivot_list *pivot_list, t_sort_tool sort_tool);
t_bi_list		*last_stack(t_bi_list *stack);
t_sort_tool		init_list(t_bi_list *stack, int output_flag, int *sorted_list,
					t_pivot_list **pivot_list);
t_pivot_list	*init_pivot_list(int all_min);

#endif
