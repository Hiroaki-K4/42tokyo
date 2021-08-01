/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:27:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/01 22:34:54 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr1_handler(int sig, siginfo_t *info, void *ucontext)
{
	printf("ucontext: %p\n", ucontext);
	printf("sigusr1_handler: %d\n", sig);
	printf("signo: %d si_code: %d\n", info->si_signo, info->si_code);
	printf("si_pid: %d si_uid: %d\n", (int)info->si_pid, (int)info->si_uid);
	exit(1);
}

void	sigusr2_handler(int sig, siginfo_t *info, void *ucontext)
{
	printf("ucontext: %p\n", ucontext);
	printf("sigusr2_handler: %d\n", sig);
	printf("signo: %d si_code: %d\n", info->si_signo, info->si_code);
	printf("si_pid: %d si_uid: %d\n", (int)info->si_pid, (int)info->si_uid);
	exit(1);
}

int	main(int argc, char *argv[])
{
	printf("argc: %d argv[0] %s\n", argc, argv[0]);
	struct sigaction sa_sigusr1;
	memset(&sa_sigusr1, 0, sizeof(sa_sigusr1));
	sa_sigusr1.sa_sigaction = sigusr1_handler;
	sa_sigusr1.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGUSR1, &sa_sigusr1, NULL) < 0)
		exit(1);

	struct sigaction sa_sigusr2;
	memset(&sa_sigusr2, 0, sizeof(sa_sigusr2));
	sa_sigusr2.sa_sigaction = sigusr2_handler;
	sa_sigusr2.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGUSR2, &sa_sigusr2, NULL) < 0)
		exit(1);
	while (1);
    return (0);
}