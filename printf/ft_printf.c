/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 17:17:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf_str(const char *arg, int *i)
{
    int len;
    // printf("begin: %c\n", arg[i]);
    len = 0;
    while (arg[*i] != '%' && arg[*i])
    {
        write(1, &arg[*i], 1);
        (*i)++;
        len++;
    }
    // write(1, arg, i);
    return (len);
}

int ft_strchr_place(const char *str, int c, int *i)
{
    int j;

    j = 0;
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
        num = -1;
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

int str_to_num(const char *arg, int *i, va_list *ap)
{
    int num;
    int j;
    
    if (*arg == '*')
    {
        num = va_arg(*ap, int);
        (*i)++;
        return (num);
    }
    j = ft_atoi(arg);
    if (j > 0)
    {
        num = j;
        while (j > 0)
        {
            j = j / 10;
            (*i)++;
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
    if (flag_list.format == 0)
        i = print_char(ap, flag_list);
    // printf("flag[0]: %d flag[1] %d\n", flag_list.flag[0], flag_list.flag[1]);
    // printf("field: %d\n", flag_list.field);
    // printf("precision: %d\n", flag_list.precision);
    // printf("format: %d\n", flag_list.format);
    return (i);
}

int ft_printf_per(const char *arg, int *i, va_list *ap)
{
    int j;
    int k;
    a_list flag_list;

    (*i)++;
    // printf("ii: %d\n", *i);
    flag_list = init_list(flag_list);
    j = 0;
    // Check the flag
    while ((j = ft_strchr_place("-0", arg[*i], i)) >= 0)
        flag_list.flag[j] = 1;
    // Check the field
    flag_list.field = str_to_num(&arg[*i], i, ap);
    // Check the precision
    if (arg[*i] == '.')
    {
        (*i)++;
        flag_list.precision = str_to_num(&arg[*i], i, ap);
    }
    flag_list.format = ft_strchr_place("cspdiuxX%", arg[*i], i);
    // printf("k: %d\n", k);
    k = output_per(ap, flag_list);
    // Output
    return (k);
}

a_list init_list(a_list flag_list)
{
    flag_list.flag[0] = 0;
    flag_list.flag[1] = 0;
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
    // printf("begin: %c\n", arg[16]);
    print_len = 0;
    while (i >= 0 && arg[i])
    {
        if (arg[i] != '%')
        {
            // printf("arg: %d\n", i);
            print_len += ft_printf_str(arg, &i);
            // printf("arg: %c\n", arg[i]);
            // printf("no");
        }
        else
        {
            print_len += ft_printf_per(arg, &i, &ap);
            // printf("arg: %c\n", arg[i]);
            // printf("i: %d\n", i);
            // printf("yes");
        }
        // printf("start: %d\n", i);
    }
    printf("len: %d\n", print_len);
    va_end(ap);
    // printf("i: %d\n", i);
    return (i);
}