/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/02 22:36:46 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf_str(const char *arg, int i)
{
    while (arg[i] != '%' && arg[i])
        i++;
    write(1, arg, i);
    return i;
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
            return (0);
        }
    }
    va_end(ap);
    
    return (0);
}

// int ft_printf(const char *arg, ...)
// {
//     va_list ap;
//     int i;
//     int j;
//     int digit;
//     char tmp;
//     char *tmp2;
    
//     va_start(ap, arg);
//     i = 0;
//     while (arg[i])
//     {
//         if (arg[i] == '%')
//         {
//             i++;
//             if (arg[i] == 'c')
//             {
//                 tmp = (char)va_arg(ap, int);
//                 write(1, &tmp, 1);
//                 i++;
//             }
//             else if (arg[i] == 's')
//             {
//                 tmp2 = va_arg(ap, char*);
//                 ft_putstr_fd(tmp2, 1);
//                 i++;
//             }
//             else if (arg[i] == '%')
//             {
//                 while (arg[i] == '%')
//                 {
//                     write(1, "%", 1);
//                     i++;
//                 }
//             }
//             else if (ft_isdigit(arg[i]))
//             {
//                 digit = 0;
//                 while (ft_isdigit(arg[i]))
//                 {
//                     digit = ft_atoi(&arg[i]);
//                     j = 1;
//                     while (j < digit)
//                     {
//                         write(1, " ", 1);
//                         j++;
//                     }
//                     while ((digit / 10) > 0)
//                     {
//                         digit = digit / 10;
//                         i++;
//                     }
//                     i++;
//                 }
//                 if (arg[i] == 'c')
//                 {
//                     tmp = (char)va_arg(ap, int);
//                     write(1, &tmp, 1);
//                     i++;
//                 }
//                 else if (arg[i] == 's')
//                 {
                    
//                     tmp2 = va_arg(ap, char*);
//                     ft_putstr_fd(tmp2, 1);
//                     i++;
//                 }
//             }
//         }
//         else
//         {
//             write(1, &arg[i], 1);
//             i++;
//         }
//     }
//     va_end(ap);
    
//     return (0);
// }