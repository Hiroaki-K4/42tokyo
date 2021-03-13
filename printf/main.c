/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/13 16:22:19 by hkubo            ###   ########.fr       */
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
    i = printf("printf:    [%-10c]\n", 'a');
    printf("len_printf: %d\n", i);
    i = 0;
    i = ft_printf("ft_printf: [%-10c]\n", 'a');
    // printf("len_ft_printf: %d\n", i);
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