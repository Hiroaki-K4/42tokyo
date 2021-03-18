/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:07:41 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 18:42:22 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned_int(va_list *ap, a_list flag_list)
{
    unsigned int num;
    int len;
    int keta;
    char *str_num;
    
    len = 0;
    num = va_arg(*ap, unsigned int);
    str_num = ft_itoa_unsigned(num);
    keta = ft_strlen(str_num);
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
    return(len);
}