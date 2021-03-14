/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:01:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/14 11:28:29 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int no_field(int num, char *str, a_list flag_list)
{
    // if (flag_list.precision )
    printf("flag: %d\n", flag_list.precision);
    printf("num: %d\n", num);
    printf("str: %s\n", str);
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
        printf("ok\n");
    }
    // else
    //     len = no_field(num, str_num, flag_list);
    printf("num: %d\n", num);
    printf("flag: %d\n", flag_list.precision);
    return(len);
}