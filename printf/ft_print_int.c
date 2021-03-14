/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:01:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/14 15:05:50 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int no_field_int(int num, char *str, a_list flag_list)
{
    int len;
    int digit;

    if (num >= 0)
        digit = ft_strlen(str);
    else
        digit = ft_strlen(str) - 1;
    if (flag_list.precision > digit)
    {
        if (num < 0)
        {
            str = ft_itoa(num * (-1));
            write(1, "-", 1);
            len = flag_list.precision + 1;
        }
        else
            len = flag_list.precision;
        while (flag_list.precision - digit > 0)
        {
            write(1, "0", 1);
            digit++;
        }
        write(1, str, ft_strlen(str));
    }
    else
    {
        write(1, str, ft_strlen(str));
        len = ft_strlen(str);
    }
    return (len);
}

int field_no_precision(int num, char *str, a_list flag_list)
{
    if (flag_list.flag[1] == 1)
    {
        printf("ok2\n");
    }
    else
    {
        
        printf("ok3\n");
    }
    return (0);
}

int print_int(va_list *ap, a_list flag_list)
{
    int num;
    int len;
    char *str_num;

    len = 0;
    num = va_arg(*ap, int);
    str_num = ft_itoa(num);
    if (flag_list.field > (int)ft_strlen(str_num))
    {
        //many func
        if (flag_list.flag[0] == 1)
        {
            printf("ok\n");
        }
        else
        {
            len = field_no_precision(num, str_num, flag_list);
        }
    }
    else
        len = no_field_int(num, str_num, flag_list);
    return(len);
}