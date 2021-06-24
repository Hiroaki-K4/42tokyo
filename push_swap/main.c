/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:51 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/24 22:49:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int str_to_digit(const char *arg)
{
    int i;
    int flag;
    size_t num;

    flag = 1;
    i = 0;
    while (arg[i] == '-' || arg[i] == '+')
    {
        if (arg[i] == '-')
            flag = flag * (-1);
        if (i == (int)ft_strlen(arg) - 1)
            return (-1);
        i++;
    }
    num = 0;
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (-1);
        num = (10 * num) + (arg[i] - '0');
        i++;
    }
    if ((flag == 1 && num > 2147483647) || (flag == -1 && num > 2147483648))
        return (-1);
    return (0);
}

int main(int argc, char *argv[])
{
    int i;
    int num;

    i = 1;
    while (i < argc)
    {
        num = str_to_digit(argv[i]);
        if (num == -1)
        {
            write(1, "Error\n", 6);
            exit(0);
        }
        printf("arg: %d\n", num);
        i++;
    }
    return (0);
}