/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:44:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 21:24:02 by hkubo            ###   ########.fr       */
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

int field_no_flag(char *str, a_list flag_list)
{
    int i;
    int len;
    
    len = 0;
    if (flag_list.precision != -1 && flag_list.precision < ft_strlen(str))
    {
        i = flag_list.precision;
        while (flag_list.field - i)
        {
            write(1, " ", 1);
            i++;
        }
        write(1, str, flag_list.precision);
    }
    else
    {
        i = 1;
        while (flag_list.field - ft_strlen(str) - i)
        {
            write(1, " ", 1);
            i++;
        }
        write(1, str, ft_strlen(str));
    }
    return (len);
}

int no_field(char *str, a_list flag_list)
{
    int len;
    
    if (flag_list.precision != -1)
    {
        while (len < flag_list.precision && str[len])
        {
            write(1, &str[len], 1);
            len++;
        }
    }
    else
    {
        write(1, str, ft_strlen(str));
        len = ft_strlen(str);
    }
    len = flag_list.field;
    return (len);
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
            // if (flag_list.precision != -1)
            //     len = field_pre(str, flag_list);
            // else
            //     len = field_only(str, flag_list);
            len = field_no_flag(str, flag_list);
        }
    }
    else
        len = no_field(str, flag_list);
    // printf("len: %d\n", len);
    // printf("str: %s\n", str);
    // printf("flag: %d\n", flag_list.precision);
    return (len);
}