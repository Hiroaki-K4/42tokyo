/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:01:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/14 11:20:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int minus_num(int num, a_list flag_list)
{
    // if (flag_list.precision )
    printf("flag: %d\n", flag_list.precision);
    printf("num: %d\n", num);
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
    // if (flag_list.field )
    printf("str_num: %s\n", str_num);
    printf("num: %d\n", num);
    printf("flag: %d\n", flag_list.precision);
    return(len);
}