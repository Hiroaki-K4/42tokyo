/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:15:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/23 11:34:55 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_len(t_plist flag_list, unsigned int num, char *str_num)
{
	int len;

	if (flag_list.field > (int)ft_strlen(str_num))
	{
		if (flag_list.precision > (int)ft_strlen(str_num))
			len = field_precision(num, str_num, flag_list, 0);
		else
			len = field_no_precision(num, str_num, flag_list, 0);
	}
	else
		len = no_field_int(num, str_num, flag_list, 0);
	return (len);
}

int	print_hex(va_list *ap, t_plist flag_list, int len)
{
	unsigned	int	num;
	char			*str_num;

	num = va_arg(*ap, unsigned int);
	if (flag_list.format == 6)
		str_num = ft_itoa_hex(num, "0123456789abcdef");
	else
		str_num = ft_itoa_hex(num, "0123456789ABCDEF");
	if (!(str_num))
		return (-1);
	if ((int)num < 0)
		num *= -1;
	if (flag_list.flag[1] == 1 && flag_list.precision != -1)
		flag_list.flag[1] = 0;
	if (flag_list.precision == 0 && num == 0)
	{
		free(str_num);
		return (pre_arg_zero(flag_list));
	}
	len = get_hex_len(flag_list, num, str_num);
	free(str_num);
	return (len);
}
