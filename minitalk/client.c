/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:44:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/07 20:48:53 by hkubo            ###   ########.fr       */
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
    while (i < 7)
    {
        sleep(1/100);
        bit = (uc >> i) & 1;
        if (bit == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                printf("kill error\n");
        }
        if (bit == 1)
        {
            if (kill(pid, SIGUSR2) == -1)
                printf("kill error\n");
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int i;
	printf("argc: %d word: %s\n", argc, argv[2]);
    i = 0;
    while (i < ft_strlen(argv[2]))
    {
        send_char(ft_atoi(argv[1]), argv[2][i]);
        i++;
    }
    // send_char(ft_atoi(argv[1]), argv[2][0]);
    return (0);
}