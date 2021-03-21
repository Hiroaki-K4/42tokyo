/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:21:37 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/21 19:08:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap, t_plist flag_list)
{
	int		len;
	char	pub;

	len = 0;
	pub = va_arg(*ap, int);
	if (flag_list.field != -1)
	{
		if (flag_list.flag[0] == 1)
		{
			write(1, &pub, 1);
			len++;
			while (flag_list.field-- > 1)
			{
				write(1, " ", 1);
				// flag_list.field--;
				len++;
			}
		}
		else
		{
			while (flag_list.field-- > 1)
			{
				write(1, " ", 1);
				// flag_list.field--;
				len++;
			}
			write(1, &pub, 1);
			len++;
		}
	}
	else
	{
		write(1, &pub, 1);
		len = 1;
	}
	return (len);
}
