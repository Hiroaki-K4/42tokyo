/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/28 21:40:30 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    char samp1 = 'b';
    char *samp2 = "ccc";
    
    printf("printf: %c\n", 'a');
    printf("printf: %c\n", samp1);
    printf("printf: %s\n", "ccc");
    printf("printf: %s\n", samp2);
    ft_printf("ft_printf: %c\n", 'a');
    ft_printf("ft_printf: %c\n", samp1);
    ft_printf("ft_printf: %s\n", "ccc");
    ft_printf("ft_printf: %s\n", samp2);
    return (0);
}