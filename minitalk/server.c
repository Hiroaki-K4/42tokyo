/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:27:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/03 23:10:22 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == 10)
		printf("SIGUSR1\n");
	else if (sig == 12)
		printf("SIGUSR2\n");
	printf("ucontext: %p\n", ucontext);
	printf("signo: %d si_code: %d\n", info->si_signo, info->si_code);
	printf("si_pid: %d si_uid: %d\n", (int)info->si_pid, (int)info->si_uid);
}

int	main(int argc, char *argv[])
{
	printf("argc: %d argv[0] %s\n", argc, argv[0]);
	struct sigaction sigusr;
	ft_bzero(&sigusr, sizeof(struct sigaction));
	sigusr.sa_sigaction = sigusr_handler;
	sigemptyset(&sigusr.sa_mask);
	sigusr.sa_flags = SA_SIGINFO;
	// while (1)
	// {
	if (sigaction(SIGUSR1, &sigusr, NULL) < 0)
		printf("error1\n");
	if (sigaction(SIGUSR2, &sigusr, NULL) < 0)
		printf("error2\n");
	// }
	while (1);
    return (0);
}