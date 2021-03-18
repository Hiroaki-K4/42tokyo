/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:41:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 21:27:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(va_list *ap, a_list flag_list)
{
    // int len;
    void *num;
    
    num = va_arg(*ap, void *);
    // len = ft_strlen((char*)num);
    // printf("len: %d\n", len);
    // if (flag_list)
    printf("num: %d\n", (int*)num);
    // printf("num: %p\n", &num);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}