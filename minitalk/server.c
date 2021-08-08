/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:27:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/08 19:47:28 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_bit_store(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_bit_store[i] = -1;
		i++;
	}
}

int	get_end_pos(void)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if (g_bit_store[i] == -1)
			break ;
		i--;
	}
	return (i);
}

int	binary_pow(int a, int b)
{
	int	ans;

	ans = 1;
	if (b == 0)
		return (1);
	while (b > 0)
	{
		ans = ans * a;
		b--;
	}
	return (ans);
}

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
	int		end_pos;
	int		new_bit;
	char	ascii_char;

	(void)info;
	(void)ucontext;
	new_bit = -2;
	if (sig == 10 || sig == 30)
		new_bit = 0;
	else if (sig == 12 || sig == 31)
		new_bit = 1;
	end_pos = get_end_pos();
	if (end_pos == -1)
	{
		init_bit_store();
		g_bit_store[6] = new_bit;
	}
	else if (end_pos == 0)
	{
		g_bit_store[end_pos] = new_bit;
		ascii_char = (char)bit_to_ascii();
		write(1, &ascii_char, 1);
	}
	else
		g_bit_store[end_pos] = new_bit;
}

int	main(int argc, char *argv[])
{
	char				*pid;
	struct sigaction	sigusr;

	(void)argc;
	(void)argv;
	pid = ft_itoa((int)getpid());
	write(1, pid, (int)ft_strlen(pid));
	write(1, "\n", 1);
	ft_bzero(&sigusr, sizeof(struct sigaction));
	sigusr.sa_sigaction = sigusr_handler;
	sigemptyset(&sigusr.sa_mask);
	sigusr.sa_flags = SA_SIGINFO;
	init_bit_store();
	if (sigaction(SIGUSR1, &sigusr, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &sigusr, NULL) < 0)
		exit(1);
	while (1)
		continue ;
	return (0);
}
