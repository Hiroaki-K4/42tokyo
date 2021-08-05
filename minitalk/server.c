/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:27:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/05 23:19:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bit_store[8];

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
	int	i;
	int	end_pos;
	int	new_bit;

	printf("bit_store: %d\n", bit_store[0]);
	if (sig == 10)
		new_bit = 0;
	else if (sig == 12)
		new_bit = 1;
	printf("new_bit: %d\n", new_bit);
	end_pos = -1;
	i = 0;
	while (i < 7)
	{
		if (bit_store[i] == -1)
		{
			end_pos = i;
			continue;
		}
		i++;
	}
	while (end_pos >= 0)
	{
		bit_store[end_pos + 1] = bit_store[end_pos];
		end_pos--;
	}
	bit_store[0] = new_bit;
	i = 0;
	while (bit_store[i] != -1)
	{
		printf("%d", bit_store[i]);
		i++;
	}
	printf("\n");
	// if (sig == 10)
	// 	printf("SIGUSR1\n");
	// else if (sig == 12)
	// 	printf("SIGUSR2\n");
	printf("ucontext: %p\n", ucontext);
	printf("signo: %d si_code: %d\n", info->si_signo, info->si_code);
}

int	main(int argc, char *argv[])
{
	printf("argc: %d argv[0] %s\n", argc, argv[0]);
	struct sigaction sigusr;
	ft_bzero(&sigusr, sizeof(struct sigaction));
	sigusr.sa_sigaction = sigusr_handler;
	sigemptyset(&sigusr.sa_mask);
	sigusr.sa_flags = SA_SIGINFO;
	bit_store[0] = -1;
	if (sigaction(SIGUSR1, &sigusr, NULL) < 0)
		printf("error1\n");
	if (sigaction(SIGUSR2, &sigusr, NULL) < 0)
		printf("error2\n");
	while (1);
    return (0);
}