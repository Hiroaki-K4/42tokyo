/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:15:09 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/27 20:55:39 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char *argv[])
{
	char *arg1;
	char *arg2;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	arg1 = argv[1];
	arg2 = argv[2];
	printf("arg1: %s agc2: %s\n", arg1, arg2);
	return (0);
}