/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:44:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 17:49:36 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(va_list *ap, a_list flag_list)
{
    int len;
    char *pub;

    len = 0;
    pub = va_arg(*ap, char*);
    // if (flag_list.field != -1)
    // {
    //     if (flag_list.flag[0] == 1)
    //     {
    //         if (flag_list.precision != -1)
    //         {
    //             len = field_flag_pre();
    //         }
    //         else
    //         {
    //             len = field_flag();
    //         }
    //     }
    //     else
    //     {
    //         if (flag_list.precision != -1)
    //         {
                
    //         }
    //         else
    //         {

    //         }
    //     }
    // }
    // else
    // {
    //     if (flag_list.flag[0] == 1)
    //     {
    //         if (flag_list.precision != -1)
    //         {

    //         }
    //         else
    //         {

    //         }
    //     }
    //     else
    //     {
    //         if (flag_list.precision != -1)
    //         {

    //         }
    //         else
    //         {

    //         }
    //     }
    // }
    printf("len: %d\n", len);
    printf("pub: %s\n", pub);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}