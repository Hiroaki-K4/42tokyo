/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/27 23:00:42 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    
    va_start(ap, arg);
    printf("arg: %s", arg);
    i = 0;
    while (arg[i])
    {
        if (arg[i] == '%')
        {
            i++;
            write(1, &arg[i], 1);
        }
        else
        {
            write(1, &arg[i], 1);
        }
        i++;
    }
    printf("%s\n", va_arg(ap, char*));
    printf("%s\n", va_arg(ap, char*));
    va_end(ap);
    
    return (0);
}

int main(void)
{
    char *samp1 = "aaa";
    char *samp2 = "bbb";
    ft_printf("%s %s\n", samp1, samp2);
    printf("ok\n");
    printf("%c\n", 'c');
    printf("%s\n", "ok");
    return (0);
}