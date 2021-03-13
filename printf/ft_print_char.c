/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:21:37 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 14:51:21 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_char(va_list *ap, a_list flag_list)
{
    int field_len;
    char pub;
    
    if (flag_list.field != -1)
    {
        pub = va_arg(*ap, int);
        if (flag_list.flag[0] == 1)
        {
            write(1, &pub, 1);
            while(flag_list.field > 1)
            {
                write(1, " ", 1);
                flag_list.field--;
            }
        }
        else
        {
            while(flag_list.field > 1)
            {
                write(1, " ", 1);
                flag_list.field--;
            }
            write(1, &pub, 1);
        }
    }
    else
    {
        write(1, va_arg(*ap, int), 1);
    }
}