/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:07:41 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/17 23:13:41 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned_int(va_list *ap, a_list flag_list)
{
    unsigned int num;
    
    num = va_arg(*ap, unsigned int);
    printf("num: %u\n", num);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}