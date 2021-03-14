/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/14 11:05:53 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    char samp1 = 'b';
    char *samp2 = "ccc";
    int i;
    
    i = 0;
    printf("~~char~~\n");
    i = printf("printf:    [%-10c %-c %c]\n", 'a', samp1, 'c');
    printf("len: %d\n", i);
    i = ft_printf("ft_printf: [%-10c %-c %c]\n", 'a', samp1, 'c');
    printf("len: %d\n", i);
    printf("~~string~~\n");
    i = printf("printf:    [%s]\n", "ccc");
    printf("len: %d\n", i);
    i = ft_printf("ft_printf: [%s]\n", "ccc");
    printf("len: %d\n", i);
    i = printf("printf:    [%10s]\n", "ccc");
    printf("len: %d\n", i);
    i = ft_printf("ft_printf: [%10s]\n", "ccc");
    printf("len: %d\n", i);
    i = printf("printf:    [%10.2s]\n", "ccc");
    printf("len: %d\n", i);
    i = ft_printf("ft_printf: [%10.2s]\n", "ccc");
    printf("len: %d\n", i);
    i = printf("printf:    [%-10.2s]\n", "ccc");
    printf("len: %d\n", i);
    i = ft_printf("ft_printf: [%-10.2s]\n", "ccc");
    printf("len: %d\n", i);
    i = printf("printf:    [%-10s]\n", "ccc");
    printf("len: %d\n", i);
    i = ft_printf("ft_printf: [%-10s]\n", "ccc");
    printf("len: %d\n", i);
    printf("~~int~~\n");
    i = printf("printf:    [%d]\n", 300);
    printf("len: %d\n", i);
    // i = ft_printf("ft_printf: [%d]\n", 300);
    // printf("len: %d\n", i);
    i = printf("printf:    [%2d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%-10d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%010d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%10.5d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%-10.5d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%10.d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%.3d]\n", 0);
    printf("len: %d\n", i);
    i = printf("printf:    [%-10.2d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%-.5d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%.5d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%.4d]\n", -20);
    printf("len: %d\n", i);
    return (0);
}