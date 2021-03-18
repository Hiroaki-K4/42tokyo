/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:41:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 22:30:56 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(va_list *ap, a_list flag_list)
{
    // int len;
    unsigned long num;
    char *str_num;
    int keta;
    int len;
    char *ans_str;
    int i;
    
    num = va_arg(*ap, unsigned long);
    str_num = ft_itoa_hex_long(num, "0123456789abcdef");
    // tmp = (unsigned int)&num;
    keta = ft_strlen(str_num);
    if (!(ans_str = (char *)malloc(sizeof(char) * (keta + 3))))
		return (-1);
    ans_str[keta] = '\0';
    ans_str[0] = '0';
    ans_str[1] = 'x';
    i = 0;
    while (str_num[i])
    {
        ans_str[i + 2] = str_num[i];
        i++;
    }
    if (flag_list.flag[1] == 1 && flag_list.precision != -1)
        flag_list.flag[1] = 0;
    if (flag_list.precision == 0 && num == 0)
        return (pre_arg_zero(flag_list));
    if (flag_list.field > (int)ft_strlen(ans_str))
    {
        if (flag_list.precision > keta)
            len = field_precision(num, ans_str, flag_list);
        else
            len = field_no_precision(num, ans_str, flag_list);
    }
    else
        len = no_field_int(num, ans_str, flag_list);
    // printf("len: %d\n", len);
    // if (flag_list)
    // printf("num: %lu\n", num);
    // printf("str_num: %s\n", str_num);
    // printf("tmp: %u\n", tmp);
    // printf("num: %p\n", &num);
    // printf("flag: %d\n", flag_list.precision);
    return (len);
}