/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:01:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/14 11:12:57 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int minus_num(int num, a_list flag_list)
{
    printf("flag: %d\n", flag_list.precision);
    printf("num: %d\n", num);
    return (0);
}

int print_int(va_list *ap, a_list flag_list)
{
    int num;
    int len;

    len = 0;
    num = va_arg(*ap, int);
    if (num < 0)
        len = minus_num(num, flag_list);
    else
    {
        // many func
        len = 0;
    }
    printf("num: %d\n", num);
    printf("flag: %d\n", flag_list.precision);

    return(0);
}