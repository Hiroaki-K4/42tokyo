/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:15:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 11:17:48 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(va_list *ap, a_list flag_list)
{
    unsigned int num;

    num = va_arg(*ap, unsigned int);
    printf("num: %u\n", num);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}