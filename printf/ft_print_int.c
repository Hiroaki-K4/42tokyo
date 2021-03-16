/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:01:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/16 23:09:23 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int no_field_int(int num, char *str, a_list flag_list)
{
    int len;
    int digit;

    if (num >= 0)
        digit = ft_strlen(str);
    else
        digit = ft_strlen(str) - 1;
    // if (flag_list.precision == 0 && num == 0)

    if (flag_list.precision > digit)
    {
        if (num < 0)
        {
            str = ft_itoa(num * (-1));
            write(1, "-", 1);
            len = flag_list.precision + 1;
        }
        else
            len = flag_list.precision;
        while (flag_list.precision - digit > 0)
        {
            write(1, "0", 1);
            digit++;
        }
        write(1, str, ft_strlen(str));
    }
    else
    {
        // printf("ok\n");
        // printf("str: %s\n", str);
        write(1, str, ft_strlen(str));
        len = ft_strlen(str);
    }
    return (len);
}

int field_no_precision(int num, char *str, a_list flag_list)
{
    int i;    

    if (flag_list.flag[0] == 1)
    {
        write(1, str, ft_strlen(str));
        i = 0;
        while (flag_list.field - ft_strlen(str) - i)
        {
            write(1, " ", 1);
            i++;
        }
    }
    else
    {
        if (num < 0 && flag_list.flag[0] != 1 && flag_list.flag[1] == 1)
        {
            write(1, "-", 1);
            i = 0;
            while (flag_list.field - ft_strlen(str) - i)
            {
                write(1, "0", 1);
                i++;
            }
            num *= -1;
            write(1, ft_itoa(num), ft_strlen(ft_itoa(num)));
        }
        else
        {
            i = 0;
            while (flag_list.field - ft_strlen(str) - i)
            {
                if (flag_list.flag[1] == 1)
                    write(1, "0", 1);
                else
                    write(1, " ", 1);
                i++;
            }
            write(1, str, ft_strlen(str));
        }
    }
    return (flag_list.field);
}

int field_precision(int num, char *str, a_list flag_list)
{
    int i;
    int j;
    char *tmp;
    
    if (num < 0)
    {
        if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 2))))
            return (-1);
        tmp[0] = '-';
        i = 1;
        while (flag_list.precision + 2 - ft_strlen(str) - i)
        {
            tmp[i] = '0';
            i++;
        }
        j = 1;
        while (ft_strlen(str) - j)
        {
            tmp[i] = str[j];
            i++;
            j++;
        }
        tmp[i] = '\0';
    }
    else
    {
        if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 1))))
            return (-1);
        i = 0;
        while (flag_list.precision - ft_strlen(str) - i)
        {
            tmp[i] = '0';
            i++;
        }
        j = 0;
        while (ft_strlen(str) - j)
        {
            tmp[i] = str[j];
            i++;
            j++;
        }
        tmp[i] = '\0';
    }
    if (flag_list.flag[0] == 1)
    {
        write(1, tmp, ft_strlen(tmp));
        i = 0;
        while (flag_list.field - ft_strlen(tmp) - i)
        {
            write(1, " ", 1);
            i++;
        }
    }
    else
    {
        i = 0;
        while (flag_list.field - ft_strlen(tmp) - i)
        {
            write(1, " ", 1);
            i++;
        }
        write(1, tmp, ft_strlen(tmp));
    }
    free(tmp);
    return (flag_list.field);
}

int pre_arg_zero(a_list flag_list)
{
    int i;
    
    i = 0;
    // printf("flag: %d\n", flag_list.field);
    if (flag_list.field != -1)
    {
        while (flag_list.field - i > 0)
        {
            write(1, " ", 1);
            i++;
        }
    }
    return (i);
}

int print_int(va_list *ap, a_list flag_list)
{
    int num;
    int len;
    int keta;
    char *str_num;

    len = 0;
    num = va_arg(*ap, int);
    str_num = ft_itoa(num);
    keta = ft_strlen(str_num);
    if (num < 0)
        keta--;
    if (flag_list.precision == 0 && num == 0)
        len = pre_arg_zero(flag_list);
    if (flag_list.field > (int)ft_strlen(str_num))
    {
        if (flag_list.precision > keta)
            len = field_precision(num, str_num, flag_list);
        else
            len = field_no_precision(num, str_num, flag_list);
    }
    else
        len = no_field_int(num, str_num, flag_list);
    return(len);
}