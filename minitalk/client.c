/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:44:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/02 23:18:50 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char *argv[])
{
	printf("argc: %d word: %s\n", argc, argv[2]);
    // kill(ft_atoi(argv[1]), SIGUSR1);
    kill(ft_atoi(argv[1]), SIGUSR2);
    return 0;
}