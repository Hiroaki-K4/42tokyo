/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:44:36 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/10 21:12:01 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc > 127)
		return ;
	i = 0;
	while (i < 7)
	{
		usleep(50);
		bit = (uc >> i) & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		if (bit == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		return (-1);
	i = 0;
	while (i < (int)ft_strlen(argv[2]))
	{
		send_char(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	return (0);
}
