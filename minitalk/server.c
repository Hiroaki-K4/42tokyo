/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:27:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/07 21:44:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bit_store[8];

void	init_bit_store()
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bit_store[i] = -1;
		i++;
	}
}

int	get_end_pos()
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if (bit_store[i] == -1)
			break;
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

int	bit_to_ascii()
{
	int	i;
	int ascii;

	ascii = 0;
	i = 0;
	while (i < 7)
	{
		ascii += binary_pow(2, 6 - i) * bit_store[i];
		i++;
	}
	return (ascii);
}

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
	// int	i;
	int	end_pos;
	int	new_bit;
	int	ascii_num;
	char ascii_char;

	if (sig == 10)
		new_bit = 0;
	else if (sig == 12)
		new_bit = 1;
	// printf("new_bit: %d\n", new_bit);
	end_pos = get_end_pos();
	// printf("end_pos: %d\n", end_pos);
	if (end_pos == -1)
	{
		init_bit_store();
		bit_store[6] = new_bit;
	}
	else if (end_pos == 0)
	{
		bit_store[end_pos] = new_bit;
		ascii_num = bit_to_ascii();
		ascii_char = ascii_num;
		// printf("ascii: %d\n", ascii_num);
		// printf("ascii_char: %c\n", ascii_char);
		printf("~~~~~~~~~~~~~~~~~~~~~");
		printf("%c", ascii_char);
	}
	else
		bit_store[end_pos] = new_bit;
	// i = 0;
	// while (i < 7)
	// {
	// 	printf("%i", bit_store[i]);
	// 	i++;
	// }
	// printf("ok\n");
	(void)info;
	(void)ucontext.uc_stack;
	// UNUSED(ucontext);
	// printf("\nucontext: %p\n", ucontext);
	// printf("signo: %d si_code: %d\n", info->si_signo, info->si_code);
}

int	main(int argc, char *argv[])
{
	printf("argc: %d argv[0] %s\n", argc, argv[0]);
	struct sigaction sigusr;
	ft_bzero(&sigusr, sizeof(struct sigaction));
	sigusr.sa_sigaction = sigusr_handler;
	sigemptyset(&sigusr.sa_mask);
	sigusr.sa_flags = SA_SIGINFO;
	init_bit_store();
	if (sigaction(SIGUSR1, &sigusr, NULL) < 0)
		printf("error1\n");
	if (sigaction(SIGUSR2, &sigusr, NULL) < 0)
		printf("error2\n");
	while (1);
    return (0);
}