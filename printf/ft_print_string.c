/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:44:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 18:27:00 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int field_flag_pre(va_list *ap, a_list flag_list)
{
    
}


int field_flag(va_list *ap, a_list flag_list)
{
    
}

int filed_pre(va_list *ap, a_list flag_list)
{

}

int field_only(va_list *ap, a_list flag_list)
{

}

int pre_only(va_list *ap, a_list flag_list)
{

}

int no_option(va_list *ap, a_list flag_list)
{
    
}

int print_string(va_list *ap, a_list flag_list)
{
    int len;
    char *pub;

    len = 0;
    pub = va_arg(*ap, char*);
    if (flag_list.field != -1)
    {
        if (flag_list.flag[0] == 1)
        {
            if (flag_list.precision != -1)
                len = field_flag_pre(ap, flag_list);
            else
                len = field_flag(ap, flag_list);
        }
        else
        {
            if (flag_list.precision != -1)
                len = field_pre(ap, flag_list);
            else
                len = field_only(ap, flag_list);
        }
    }
    else
    {
        if (flag_list.precision != -1)
            len = pre_only(ap, flag_list);
        else
            len = no_option(ap, flag_list);
    }
    printf("len: %d\n", len);
    printf("pub: %s\n", pub);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}