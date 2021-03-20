/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/20 12:39:23 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf_str(const char *arg, int *i)
{
    int len;
    len = 0;
    while (arg[*i] != '%' && arg[*i])
    {
        write(1, &arg[*i], 1);
        (*i)++;
        len++;
    }
    return (len);
}

int ft_strchr_place(const char *str, int c, int *i, va_list *ap)
{
    int j;
    int num;
    char *str_num;

    if (c == '*')
    {
        num = va_arg(*ap, int);
        str_num = ft_itoa(num);
        printf(str_num);
        // (*i)++;
        // return (num);
    }
    j = 0;
    printf("c: %c\n", c);
    
    while (j < (int)ft_strlen(str))
    {
        if (str[j] == c)
        {
            (*i)++;
            return (j);
        }
        j++;
    }
    return (-1);
}

int str_to_field(const char *arg, int *i)
{
    int num;
    int tmp;

    num = ft_atoi(arg);
    if (num <= 0)
        num *= -1;
    else
    {
        tmp = num;
        while (tmp > 0)
        {
            tmp = tmp / 10;
            (*i)++;
        }
    }
    return (num);
}

int str_to_num(const char *arg, int *i, va_list *ap, int flag)
{
    int num;
    int j;
    int k;
    
    if (*arg == '*')
    {
        num = va_arg(*ap, int);
        (*i)++;
        return (num);
    }
    if (ft_isdigit(arg[0]) == 0 && flag == 1)
        return (0);
    j = ft_atoi(arg);
    if (j > 0)
    {
        num = j;
        k = 0;
        while (ft_isdigit(arg[k]))
        {
            (*i)++;
            k++;
        }
    }
    else if (flag == 1 && j == 0)
    {
        num = 0;
        k = 0;
        while (ft_isdigit(arg[k]))
        {
            (*i)++;
            k++;
        }
    }
    else
        num = -1;
    return (num);
}

int output_per(va_list *ap, a_list flag_list)
{
    int i;
    
    i = 0;
    // printf("format: %d\n", flag_list.format);
    if (flag_list.format == 0)
        i = print_char(ap, flag_list);
    else if (flag_list.format == 1)
        i = print_string(ap, flag_list);
    else if (flag_list.format == 2)
        i = print_pointer(ap, flag_list);
    else if (flag_list.format == 3 || flag_list.format == 4)
        i = print_int(ap, flag_list);
    else if (flag_list.format == 5)
        i = print_unsigned_int(ap, flag_list);
    else if (flag_list.format == 6 || flag_list.format == 7)
        i = print_hex(ap, flag_list);
    else if (flag_list.format == 8)
        i = print_percent(flag_list);
    return (i);
}

int ft_printf_per(const char *arg, int *i, va_list *ap)
{
    int j;
    int k;
    a_list flag_list;

    (*i)++;
    flag_list = init_list();
    j = 0;
    // Check the flag
    while ((j = ft_strchr_place("-0", arg[*i], i, ap)) >= 0)
        flag_list.flag[j] = 1;
    // Check the field
    flag_list.field = str_to_num(&arg[*i], i, ap, 0);
    // Check the precision
    if (arg[*i] == '.')
    {
        // printf("argc: %c\n", arg[*i]);
        (*i)++;
        flag_list.precision = str_to_num(&arg[*i], i, ap, 1);
        // printf("pre: %d\n", flag_list.precision);
    }
    // printf("arg: %s\n", &arg[*i]);
    flag_list.format = ft_strchr_place("cspdiuxX%", arg[*i], i, ap);
    // printf("flag: %d\n", flag_list.flag[0]);
    k = output_per(ap, flag_list);
    // printf("k: %d\n", k);
    return (k);
}

// a_list init_list(a_list flag_list)
// {
//     flag_list.flag[0] = -1;
//     flag_list.flag[1] = -1;
//     flag_list.field = -1;
//     flag_list.precision = -1;
//     flag_list.format = -1;
//     return (flag_list);
// }

a_list init_list()
{
    a_list flag_list;
    
    flag_list.flag[0] = -1;
    flag_list.flag[1] = -1;
    flag_list.field = -1;
    flag_list.precision = -1;
    flag_list.format = -1;
    return (flag_list);
}

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    int print_len;
    
    va_start(ap, arg);
    i = 0;
    if (arg == NULL)
        i = -1;
    print_len = 0;
    while (i >= 0 && arg[i])
    {
        if (arg[i] != '%')
        {
            print_len += ft_printf_str(arg, &i);
        }
        else
        {
            // printf("print_len: %d\n", print_len);
            print_len += ft_printf_per(arg, &i, &ap);
            // printf("print_len: %d\n", print_len);
        }
        // printf("print_len: %d\n", print_len);
    }
    va_end(ap);
    // printf("print_len: %d\n", print_len);
    return (print_len);
}