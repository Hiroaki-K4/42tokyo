/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:05:33 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/22 09:46:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_long(unsigned long n)
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

void	field_no_precision_sub(int num, char *str, t_plist flag_list, int i)
{
	if (num < 0 && flag_list.flag[0] != 1 && flag_list.flag[1] == 1)
	{
		write(1, "-", 1);
		while (flag_list.field - ft_strlen(str) - (i++))
			write(1, "0", 1);
		num *= -1;
		write(1, ft_itoa(num), ft_strlen(ft_itoa(num)));
	}
	else
	{
		while (flag_list.field - ft_strlen(str) - (i++))
		{
			if (flag_list.flag[1] == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, str, ft_strlen(str));
	}
}