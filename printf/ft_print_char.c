/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:21:37 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 14:40:35 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_char(va_list *ap, a_list flag_list)
{
    int field_len;
    
    if (flag_list.field != -1)
    {
        if (flag_list.flag[0] == 1)
        {
            write(1, va_arg(*ap, char), 1);
            while(flag_list.field > 1)
            {
                write(1, ' ', 1);
                flag_list.field--;
            }
        }
        else
        {
            while(flag_list.field > 1)
            {
                write(1, ' ', 1);
                flag_list.field--;
            }
            write(1, va_arg(*ap, char), 1);
        }
    }
    else
    {
        write(1, va_arg(*ap, char), 1);
    }
}