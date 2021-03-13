/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:44:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 20:38:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int field_flag_pre(char *str, a_list flag_list)
{

    printf("arg: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}


int field_flag(char *str, a_list flag_list)
{

    printf("arg: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}

int field_pre(char *str, a_list flag_list)
{

    printf("arg: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}

int field_only(char *str, a_list flag_list)
{

    printf("arg: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}

int pre_only(char *str, a_list flag_list)
{

    printf("arg: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}

int no_option(char *str, a_list flag_list)
{

    printf("arg: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (0);
}

int print_string(va_list *ap, a_list flag_list)
{
    int len;
    char *str;

    len = 0;
    str = va_arg(*ap, char*);
    if (flag_list.field != -1)
    {
        if (flag_list.flag[0] == 1)
        {
            if (flag_list.precision != -1)
                len = field_flag_pre(str, flag_list);
            else
                len = field_flag(str, flag_list);
        }
        else
        {
            if (flag_list.precision != -1)
                len = field_pre(str, flag_list);
            else
                len = field_only(str, flag_list);
        }
    }
    else
    {
        if (flag_list.precision != -1)
            len = pre_only(str, flag_list);
        else
            len = no_option(str, flag_list);
    }
    printf("len: %d\n", len);
    printf("str: %s\n", str);
    printf("flag: %d\n", flag_list.precision);
    return (len);
}