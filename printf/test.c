/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/27 22:27:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *arg, ...)
{
    va_list ap;
    
    va_start(ap, arg);
    printf("%s\n", va_arg(ap, char*));
    printf("%s\n", va_arg(ap, char*));
    va_end(ap);
    
    return (0);
}

int main(void)
{
    char *samp1 = "aaa";
    char *samp2 = "bbb";
    ft_printf("%s\n", samp1, samp2);
    printf("ok\n");
    printf("%c\n", 'c');
    printf("%s\n", "ok");
    return (0);
}