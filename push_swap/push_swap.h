/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:32:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/07/03 20:33:28 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_bi_list
{
    int data;
    int start;
    struct  s_bi_list *prev;
    struct  s_bi_list *next;
}	t_bi_list;

void	error_process();
void	push_a(t_bi_list **stack_a, t_bi_list **stack_b);
void	push_b(t_bi_list **stack_a, t_bi_list **stack_b);
void	swap_a(t_bi_list *stack_a);
void	top_del(t_bi_list **list);
void	show_list(t_bi_list *list);
void	stack_init(t_bi_list **stack_a, t_bi_list **stack_b);
int	    digit_check(const char *arg);

#endif
