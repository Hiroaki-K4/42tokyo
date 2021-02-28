/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/28 10:29:39 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    char tmp;
    
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
                // write(1, "\n", 1);
                // printf("%c\n", (char)tmp);
                // write(1, &arg[i], 1);
            }
            i++;
        }
        else
        {
            write(1, &arg[i], 1);
        }
        i++;
    }
    va_end(ap);
    
    return (0);
}

int main(void)
{
    char samp1 = 'b';
    // char *samp2 = "bbb";
    printf("%c", 'a');
    printf("%c", samp1);
    ft_printf("%c", 'a');
    ft_printf("%c", samp1);
    return (0);
}