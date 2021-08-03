/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:44:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/03 23:25:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_char(pid_t pid, char c)
{
    int bit;
    int i;
    unsigned char   uc;

    uc = (unsigned char)c;
    i = 0;
    while (i < 8)
    {
        usleep(10);
        bit = (uc >> i) & 0x01;
        if (kill(pid, SIGUSR1 + bit) == -1)
            printf("kill error\n");
        i++;
    }
}

int main(int argc, char *argv[])
{
	printf("argc: %d word: %s\n", argc, argv[2]);
    // kill(ft_atoi(argv[1]), SIGUSR1);
    // kill(ft_atoi(argv[1]), SIGUSR2);
    send_char(ft_atoi(argv[1]), argv[2][0]);
    return 0;
}