/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/08 11:06:24 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf_str(const char *arg, int i)
{
    while (arg[i] != '%' && arg[i])
        i++;
    write(1, arg, i);
    printf("i: %d\n", i);
    return (i);
}

int ft_strchr_place(const char *str, int c)
{
    
}

int ft_printf_per(const char *arg, int i)
{
    int j;
    a_list flag_list;

    flag_list = init_list(flag_list);
    j = 0;
    while (j = ft_strchr_place("-0", arg[i]) >= 0)
    {
        flag_list.flag[j] = 1;
        i++;
    }
    return (i);
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
            i = ft_printf_per(arg, i);
        }
    }
    va_end(ap);
    
    return (i);
}