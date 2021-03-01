/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/01 22:00:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    char tmp;
    char *tmp2;
    
    va_start(ap, arg);
    i = 0;
    while (arg[i])
    {
        if (arg[i] == '%')
        {
            i++;
            if (arg[i] == 'c')
            {
                tmp = (char)va_arg(ap, int);
                write(1, &tmp, 1);
                i++;
            }
            else if (arg[i] == 's')
            {
                tmp2 = va_arg(ap, char*);
                ft_putstr_fd(tmp2, 1);
                i++;
            }
            else if (arg[i] == '%')
            {
                while (arg[i] == '%')
                {
                    write(1, "%", 1);
                    i++;
                }
            }
            else if (ft_isdigit(arg[i]))
            {
                printf("ok");
            }
        }
        else
        {
            write(1, &arg[i], 1);
            i++;
        }
    }
    va_end(ap);
    
    return (0);
}