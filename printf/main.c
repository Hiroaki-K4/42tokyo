/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/19 22:23:41 by hkubo            ###   ########.fr       */
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
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~string~~\n");
    i = printf("printf:    [%s]\n", NULL);
    j = ft_printf("ft_printf: [%s]\n", NULL);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-5s]\n", "goes over");
    j = ft_printf("ft_printf: [%-5s]\n", "goes over");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%3.5s]\n", "hi low");
    j = ft_printf("ft_printf: [%3.5s]\n", "hi low");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%09s]\n", "hi low");
    j = ft_printf("ft_printf: [%09s]\n", "hi low");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.00s]\n", "");
    j = ft_printf("ft_printf: [%.00s]\n", "");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
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
    i = printf("printf:    [%10.5s]\n", "ccc");
    j = ft_printf("ft_printf: [%10.5s]\n", "ccc");
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
    i = printf("printf:    [%.03s]\n", "hi");
    j = ft_printf("ft_printf: [%.03s]\n", "hi");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.09s]\n", "hi low");
    j = ft_printf("ft_printf: [%.09s]\n", "hi low");
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~int~~\n");
    i = printf("printf:    [%010.3d]\n", 8375);
    j = ft_printf("ft_printf: [%010.3d]\n", 8375);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%08.3d]\n", -8375);
    j = ft_printf("ft_printf: [%08.3d]\n", -8375);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-10.05d]\n", 300);
    j = ft_printf("ft_printf: [%-10.05d]\n", 300);
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
    i = printf("printf:    [%-10.d]\n", 0);
    j = ft_printf("ft_printf: [%-10.d]\n", 0);
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
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~unsigned int~~\n");
    i = printf("printf:    [%u]\n",  4294967295u);
    j = ft_printf("ft_printf: [%u]\n",  4294967295u);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [this %u number]\n", 0);
    j = ft_printf("ft_printf: [this %u number]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%u]\n", 2147483648);
    j = ft_printf("ft_printf: [%u]\n", 2147483648);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%3u]\n", 0);
    j = ft_printf("ft_printf: [%3u]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10u]\n", 300);
    j = ft_printf("ft_printf: [%10u]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-10u]\n", 300);
    j = ft_printf("ft_printf: [%-10u]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%010u]\n", 300);
    j = ft_printf("ft_printf: [%010u]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-010u]\n", 300);
    j = ft_printf("ft_printf: [%-010u]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.5u]\n", 300);
    j = ft_printf("ft_printf: [%10.5u]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.2u]\n", 300);
    j = ft_printf("ft_printf: [%10.2u]\n", 300);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%9.2u]\n", 2147483648);
    j = ft_printf("ft_printf: [%9.2u]\n", 2147483648);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~hex x~~\n");
    i = printf("printf:    [this %x number]\n", 0);
    j = ft_printf("ft_printf: [this %x number]\n", 0);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10x]\n", 10);
    j = ft_printf("ft_printf: [%10x]\n", 10);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.5x]\n", 352);
    j = ft_printf("ft_printf: [%10.5x]\n", 352);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.2x]\n", 1600);
    j = ft_printf("ft_printf: [%10.2x]\n", 1600);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~hex X~~\n");
    i = printf("printf:    [%X]\n", 10);
    j = ft_printf("ft_printf: [%X]\n", 10);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%X]\n", 352);
    j = ft_printf("ft_printf: [%X]\n", 352);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%X]\n", 1600);
    j = ft_printf("ft_printf: [%X]\n", 1600);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~pointer p~~\n");
    int a;
    i = printf("printf:    [%p]\n", &a);
    j = ft_printf("ft_printf: [%p]\n", &a);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    // i = printf("printf:    [%2.p]\n", NULL);
    // j = ft_printf("ft_printf: [%2.p]\n", NULL);
    // printf("len: %d\n", i);
    // printf("len: %d\n", j);
    i = printf("printf:    [%2p]\n", 1234);
    j = ft_printf("ft_printf: [%2p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10p]\n", 1234);
    j = ft_printf("ft_printf: [%10p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-10p]\n", 1234);
    j = ft_printf("ft_printf: [%-10p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%010p]\n", 1234);
    j = ft_printf("ft_printf: [%010p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%-010p]\n", 1234);
    j = ft_printf("ft_printf: [%-010p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%10.6p]\n", 1234);
    j = ft_printf("ft_printf: [%10.6p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    i = printf("printf:    [%.6p]\n", 1234);
    j = ft_printf("ft_printf: [%.6p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);
    // char b;
    // i = printf("printf:    [%15.16p]\n", &b);
// j = ft_printf("ft_printf: [%15.16p]\n", &b);
    // printf("len: %d\n", i);
    // printf("len: %d\n", j);
    i = printf("printf:    [%9.2p]\n", 1234);
    j = ft_printf("ft_printf: [%9.2p]\n", 1234);
    printf("len: %d\n", i);
    printf("len: %d\n", j);


    // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    // printf("~~percent~~\n");
    // i = printf("printf:    [%3.%]\n");
    // j = ft_printf("ft_printf: [%3.%]\n");
    // printf("len: %d\n", i);
    // printf("len: %d\n", j);
    // i = printf("printf:    [%%]\n", 300);
    // j = ft_printf("ft_printf: [%%]\n", 300);
    // printf("len: %d\n", i);
    // printf("len: %d\n", j);
    // i = printf("printf:    [%d%]\n", 300);
    // j = ft_printf("ft_printf: [%d%]\n", 300);
    // printf("len: %d\n", i);
    // printf("len: %d\n", j);
    // i = printf("printf:    [%.3]\n", 300);
    // j = ft_printf("ft_printf: [%.3]\n", 300);
    // printf("len: %d\n", i);
    // printf("len: %d\n", j);
    return (0);
}