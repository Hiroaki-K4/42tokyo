/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/12 09:37:23 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf_str(const char *arg, int i)
{
    while (arg[i] != '%' && arg[i])
        i++;
    write(1, arg, i);
    return (i);
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

int output_per(a_list flag_list)
{
    printf("flag[0]: %d flag[1] %d\n", flag_list.flag[0], flag_list.flag[1]);
    printf("field: %d\n", flag_list.field);
    printf("precision: %d\n", flag_list.precision);
    printf("format: %d\n", flag_list.format);
    return (0);
}

int ft_printf_per(const char *arg, int i, va_list *ap)
{
    int j;
    int k;
    a_list flag_list;

    flag_list = init_list(flag_list);
    j = 0;
    // Check the flag
    while ((j = ft_strchr_place("-0", arg[i], &i)) >= 0)
        flag_list.flag[j] = 1;
    // printf("flag[0]: %d flag[1] %d\n", flag_list.flag[0], flag_list.flag[1]);
    // Check the field
    flag_list.field = str_to_num(&arg[i], &i, ap);
    // printf("field: %d\n", flag_list.field);
    // Check the precision
    if (arg[i] == '.')
    {
        i++;
        flag_list.precision = str_to_num(&arg[i], &i, ap);
    }
    // printf("precision: %d\n", flag_list.precision);
    flag_list.format = ft_strchr_place("cspdiuxX%", arg[i], &i);
    // printf("format: %d\n", flag_list.format);
    // printf("i: %d now: %c\n", i, arg[i]);
    k = output_per(flag_list);
    printf("k: %d\n", k);
    // Output
    return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char const	*ptr_s;
	int					i;

	ptr_s = (unsigned char const *)s;
	i = 0;
	while (ptr_s[i] != '\0')
	{
		if (ptr_s[i] == (unsigned char)c)
			return (char *)(s + i);
		i++;
	}
	if (ptr_s[i] == '\0' && ptr_s[i] == (unsigned char)c)
		return (char *)(s + i);
	return (NULL);
}

a_list init_list(a_list flag_list)
{
    flag_list.flag[0] = 0;
    flag_list.flag[1] = 0;
    return (flag_list);
}

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    
    va_start(ap, arg);
    i = 0;
    if (arg == NULL)
        i = -1;
    while (i >= 0 && *arg)
    {
        if (arg[i] != '%')
            i = ft_printf_str(arg, i);
        else
        {
            i = ft_printf_per(arg, i+1, &ap);
        }
    }
    va_end(ap);
    
    return (i);
}