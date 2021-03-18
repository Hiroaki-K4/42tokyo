/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:41:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 21:43:09 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(va_list *ap, a_list flag_list)
{
    // int len;
    unsigned int num;
    // unsigned int tmp;
    
    num = va_arg(*ap, unsigned int);
    // tmp = (unsigned int)&num;
    // len = ft_strlen((char*)num);
    // printf("len: %d\n", len);
    // if (flag_list)
    printf("num: %u\n", num);
    // printf("tmp: %u\n", tmp);
    // printf("num: %p\n", &num);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}