/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:05:33 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/21 22:07:42 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_len_long(unsigned long n)
{
	unsigned long	i;
	int				len;

	i = n / 16;
	if (i != 0)
	{
		len = 2;
		while (i >= 16)
		{
			len++;
			i = i / 16;
		}
	}
	else
		len = 1;
	return (len);
}
