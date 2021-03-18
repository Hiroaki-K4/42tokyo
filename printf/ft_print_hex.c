/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:15:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 17:51:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(va_list *ap, a_list flag_list)
{
    unsigned int num;
    char *str;

    num = va_arg(*ap, unsigned int);
    str = ft_itoa_hex(num, "0123456789abcdef");
    printf("str: %s\n", str);
    printf("num: %u\n", num);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}