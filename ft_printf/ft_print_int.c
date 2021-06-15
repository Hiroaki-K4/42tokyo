/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:01:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/25 11:33:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_field_int(int num, char *str, t_plist flag_list, int len)
{
	int		digit;

	digit = ft_strlen(str);
	if (num < 0)
		digit = ft_strlen(str) - 1;
	if (flag_list.precision > digit)
	{
		len = flag_list.precision;
		if (num < 0)
			len = no_field_int_sub(flag_list, num, digit);
		else
		{
			while (flag_list.precision - (digit++) > 0)
				write(1, "0", 1);
			write(1, str, ft_strlen(str));
		}
	}
	else
	{
		write(1, str, ft_strlen(str));
		len = ft_strlen(str);
	}
	return (len);
}

int	field_no_precision(int num, char *str, t_plist flag_list, int i)
{
	if (flag_list.flag[0] == 1)
	{
		write(1, str, ft_strlen(str));
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
			write(1, " ", 1);
	}
	else
	{
		if (field_no_precision_sub(num, str, flag_list, i) == -1)
			return (-1);
	}
	return (flag_list.field);
}

int	field_precision(int num, char *str, t_plist flag_list, int i)
{
	char	*tmp;

	if (!(tmp = field_precision_sub(num, str, flag_list, 0)))
		return (-1);
	if (flag_list.flag[0] == 1)
	{
		write(1, tmp, ft_strlen(tmp));
		i = 0;
		while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
			write(1, " ", 1);
	}
	else
	{
		i = 0;
		while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
			write(1, " ", 1);
		write(1, tmp, ft_strlen(tmp));
		if (flag_list.precision > flag_list.field)
		{
			free(tmp);
			return (flag_list.precision);
		}
	}
	free(tmp);
	return (flag_list.field);
}

int	pre_arg_zero(t_plist flag_list)
{
	int i;

	i = 0;
	if (flag_list.field != -1)
	{
		while (flag_list.field - i > 0)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}

int	print_int(va_list *ap, t_plist flag_list)
{
	int		num;
	int		len;
	int		keta;
	char	*str_num;

	len = 0;
	num = va_arg(*ap, int);
	if (!(str_num = ft_itoa(num)))
		return (-1);
	keta = ft_strlen(str_num);
	if (flag_list.flag[1] == 1 && flag_list.precision != -1)
		flag_list.flag[1] = 0;
	if (num < 0)
		keta--;
	if (flag_list.precision == 0 && num == 0)
	{
		free(str_num);
		return (pre_arg_zero(flag_list));
	}
	len = print_int_len(flag_list, str_num, keta, num);
	free(str_num);
	return (len);
}
