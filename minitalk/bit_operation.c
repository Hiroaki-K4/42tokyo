/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:03:04 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/08 17:03:32 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bit_to_ascii(void)
{
	int	i;
	int	ascii;

	ascii = 0;
	i = 0;
	while (i < 7)
	{
		ascii += binary_pow(2, 6 - i) * g_bit_store[i];
		i++;
	}
	return (ascii);
}
