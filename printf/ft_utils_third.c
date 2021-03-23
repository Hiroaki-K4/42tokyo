/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:48:46 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/23 11:50:14 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer_len(t_plist flag_list, int size, int i, char *ans_str)
{
    int len;

    if (flag_list.field > size)
		len = make_return_len(flag_list, size, ans_str, 0);
	else
	{
		while (ans_str[i])
			write(1, &ans_str[i++], 1);
		len = size;
	}
    return (len);
}