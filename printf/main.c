/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 22:21:34 by hkubo            ###   ########.fr       */
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
    i = ft_printf("ft_printf: [%d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%10d]\n", 300);
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
    i = printf("printf:    [%10.d]\n", 300);
    printf("len: %d\n", i);
    i = printf("printf:    [%-10.2d]\n", 300);
    printf("len: %d\n", i);
    // ft_printf("ft_printf: [aa]\n");
    // ft_printf("ft_printf: [%0-2425.3d]\n", 10);
    // ft_printf("ft_printf: [%0-*.*ad]\n", 2425, 3, 10);
    // printf("printf:    [%010d]\n", 10);
    // ft_printf("ft_printf: [%c]\n", 'a');
    // printf("printf:    [%c]\n", samp1);
    // ft_printf("ft_printf: [%c]\n", samp1);
    // printf("printf:    [%s]\n", "ccc");
    // ft_printf("ft_printf: [%s]\n", "ccc");
    // printf("printf:    [%s]\n", samp2);
    // ft_printf("ft_printf: [%s]\n", samp2);
    // printf("printf:    [%c %s]\n", samp1, samp2);
    // ft_printf("ft_printf: [%c %s]\n", samp1, samp2);
    // printf("printf:    [%s %c]\n", samp2, samp1);
    // ft_printf("ft_printf: [%s %c]\n", samp2, samp1);
    // printf("printf:    [%s %c %%%]\n", samp2, samp1);
    // ft_printf("ft_printf: [%s %c %%%]\n", samp2, samp1);
    // printf("printf:    [%10c]\n", 'a');
    // ft_printf("ft_printf: [%10c]\n", 'a');
    // printf("printf:    [%10s]\n", "bbb");
    // ft_printf("ft_printf: [%10s]\n", "bbb");
    return (0);
}