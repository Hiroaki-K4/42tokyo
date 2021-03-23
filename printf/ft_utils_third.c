/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:48:46 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/23 12:00:43 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer_len(t_plist flag_list, int size, int i, char *ans_str)
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

int	print_unsigned_int_len(t_plist flag_list, int keta, char *str_num)
{
	int len;

	if (flag_list.precision > keta)
		len = field_precision_unsigned(str_num, flag_list, 0, 0);
	else
		len = field_no_precision_unsigned(str_num, flag_list);
	return (len);
}
