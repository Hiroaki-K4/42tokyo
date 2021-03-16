/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/16 22:58:53 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    char samp1 = 'b';
    char *samp2 = "ccc";
    int i;
    int j;
    
    i = 0;
    j = 0;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~char~~\n");
    i = printf("printf:    [%-10c %-c %c]\n", 'a', samp1, 'c');
    j = ft_printf("ft_printf: [%-10c %-c %c]\n", 'a', samp1, 'c');
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    printf("~~string~~\n");
    i = printf("printf:    [%s]\n", "ccc");
    j = ft_printf("ft_printf: [%s]\n", "ccc");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10s]\n", "ccc");
    j = ft_printf("ft_printf: [%10s]\n", "ccc");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.2s]\n", "ccc");
    j = ft_printf("ft_printf: [%10.2s]\n", "ccc");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-10.2s]\n", "ccc");
    j = ft_printf("ft_printf: [%-10.2s]\n", "ccc");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-10s]\n", "ccc");
    j = ft_printf("ft_printf: [%-10s]\n", "ccc");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~int~~\n");
    i = printf("printf:    [%-010.5d]\n", 300);
    j = ft_printf("ft_printf: [%-10.5d]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-10d]\n", -300);
    j = ft_printf("ft_printf: [%-10d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%0d]\n", -300);
    j = ft_printf("ft_printf: [%0d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%010d]\n", 300);
    j = ft_printf("ft_printf: [%010d]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.2d]\n", -300);
    j = ft_printf("ft_printf: [%10.2d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-.5d]\n", -300);
    j = ft_printf("ft_printf: [%-.5d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%0.5d]\n", -300);
    j = ft_printf("ft_printf: [%0.5d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.5d]\n", -300);
    j = ft_printf("ft_printf: [%.5d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-.0d]\n", -300);
    j = ft_printf("ft_printf: [%-.0d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.0d]\n", -300);
    j = ft_printf("ft_printf: [%.0d]\n", -300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%0.0d]\n", 0);
    j = ft_printf("ft_printf: [%0.0d]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-.0d]\n", 0);
    j = ft_printf("ft_printf: [%-.0d]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.d]\n", 0);
    j = ft_printf("ft_printf: [%.d]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10d]\n", 0);
    j = ft_printf("ft_printf: [%10d]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.0d]\n", 3);
    j = ft_printf("ft_printf: [%.0d]\n", 3);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.d]\n", 30);
    j = ft_printf("ft_printf: [%.d]\n", 30);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    return (0);
}