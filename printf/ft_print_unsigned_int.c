/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:07:41 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 10:32:33 by hkubo            ###   ########.fr       */
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
    // printf("num: %d\n", num);
    str_num = ft_itoa_unsigned(num);
    // printf("str_num: %s\n", str_num);
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
    // printf("len: %d\n", len);
    return(len);
    




    // num = va_arg(*ap, unsigned int);
    // printf("num: %u\n", num);
    // printf("flag: %d\n", flag_list.precision);
    // return (0);
}

// int print_int(va_list *ap, a_list flag_list)
// {
//     int num;
//     int len;
//     int keta;
//     char *str_num;

//     len = 0;
//     num = va_arg(*ap, int);
//     str_num = ft_itoa(num);
//     keta = ft_strlen(str_num);
//     if (flag_list.flag[1] == 1 && flag_list.precision != -1)
//         flag_list.flag[1] = 0;
//     if (num < 0)
//         keta--;
//     if (flag_list.precision == 0 && num == 0)
//         return (pre_arg_zero(flag_list));
//     if (flag_list.field > (int)ft_strlen(str_num))
//     {
//         if (flag_list.precision > keta)
//             len = field_precision(num, str_num, flag_list);
//         else
//             len = field_no_precision(num, str_num, flag_list);
//     }
//     else
//         len = no_field_int(num, str_num, flag_list);
//     // printf("len: %d\n", len);
//     return(len);
// }