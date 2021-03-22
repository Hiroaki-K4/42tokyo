/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:28:58 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/22 11:50:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_plist flag_list, int i, int len)
{
	if (flag_list.field > 1)
	{
		if (flag_list.flag[0] == 1)
		{
			write(1, "%", 1);
			while ((flag_list.field - 1 - (i++)) > 0)
				write(1, " ", 1);
		}
		else
		{
			if (flag_list.flag[1] == 1)
			{
				while ((flag_list.field - 1 - (i++)) > 0)
					write(1, "0", 1);
				write(1, "%", 1);
			}
			else
			{
				while ((flag_list.field - 1 - (i++)) > 0)
					write(1, " ", 1);
				write(1, "%", 1);
			}
		}
		len = flag_list.field;
	}
	else
	{
		write(1, "%", 1);
		len = 1;
	}
	return (len);
}
