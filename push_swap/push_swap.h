/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:32:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/10 16:47:08 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_bi_list
{
	int					data;
	struct s_bi_list	*prev;
	struct s_bi_list	*next;
}	t_bi_list;

void		error_process();
void		push_a(t_bi_list **stack_a, t_bi_list **stack_b);
void		push_b(t_bi_list **stack_a, t_bi_list **stack_b);
void		swap_a(t_bi_list *stack_a);
void		swap_b(t_bi_list *stack_b);
void		swap_ab(t_bi_list **stack_a, t_bi_list **stack_b);
void		top_del(t_bi_list **list);
void		show_list(t_bi_list *list);
void		stack_init(t_bi_list **stack);
void		rotate_a(t_bi_list **stack_a);
void		rotate_b(t_bi_list **stack_b);
void		rotate_ab(t_bi_list **stack_a, t_bi_list **stack_b);
void		reverse_rotate_a(t_bi_list **stack_a);
void		reverse_rotate_b(t_bi_list **stack_b);
void		reverse_rotate_ab(t_bi_list **stack_a, t_bi_list **stack_b);
void		under_six(t_bi_list **stack_a, t_bi_list **stack_b, int argc);
void		sort_three(t_bi_list **stack);
void		branch_process(int argc, t_bi_list **stack_a, t_bi_list **stack_b);
int			digit_check(const char *arg);
int			duplicate_check(int argc, char *argv[]);
int			sorted_check(t_bi_list *stack);
int			stack_min(t_bi_list *stack);
int			stack_min_limit(t_bi_list *stack, int all_min);
int			add_stack(t_bi_list **stack, int num);
int			stack_max(t_bi_list *stack);
int			stack_len(t_bi_list *stack);
int			stack_len_limit(t_bi_list *stack, int all_min);
int			find_pivot(t_bi_list *stack, int min, int max, int len);
t_bi_list	*last_stack(t_bi_list *stack);

#endif
