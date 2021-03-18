/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:15:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 18:15:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(va_list *ap, a_list flag_list)
{
    unsigned int num;
    char *str;
    int keta;
    int len;

    num = va_arg(*ap, unsigned int);
    if (flag_list.format == 6)
        str = ft_itoa_hex(num, "0123456789abcdef");
    else
        str = ft_itoa_hex(num, "0123456789ABCDEF");
    keta = ft_strlen(str);
    if (flag_list.flag[1] == 1 && flag_list.precision != -1)
        flag_list.flag[1] = 0;
    if (flag_list.precision == 0 && num == 0)
        return (pre_arg_zero(flag_list));
    if (flag_list.field > (int)ft_strlen(str_num))
    {
        if (flag_list.precision > keta)
            len = field_precision(num, str_num, flag_list);
        else
            len = field_no_precision(num, str_num, flag_list);
    }
    else
        len = no_field_int(num, str_num, flag_list);
    // printf("len: %d\n", len);
    // printf("str: %s\n", str);
    // printf("num: %u\n", num);
    // printf("flag: %d\n", flag_list.precision);
    return (len);
}