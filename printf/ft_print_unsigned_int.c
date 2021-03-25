/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:07:41 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/25 10:54:01 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_field_unsigned(char *str, t_plist flag_list)
{
	int len;
	int digit;

	digit = ft_strlen(str);
	if (flag_list.precision > digit)
	{
		len = flag_list.precision;
		while (flag_list.precision - digit > 0)
		{
			write(1, "0", 1);
			digit++;
		}
		write(1, str, ft_strlen(str));
	}
	else
	{
		write(1, str, ft_strlen(str));
		len = ft_strlen(str);
	}
	return (len);
}

char	*make_str(char *str, t_plist flag_list, int i, int j)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 1))))
		return (NULL);
	while ((flag_list.precision - ft_strlen(str) - i) > 0)
		tmp[i++] = '0';
	while ((ft_strlen(str) - j) > 0)
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	return (tmp);
}

int		field_precision_unsigned(char *str, t_plist flag_list, int i, int j)
{
	char	*tmp;

	if (!(tmp = make_str(str, flag_list, i, j)))
		return (-1);
	i = 0;
	if (flag_list.flag[0] == 1)
	{
		write(1, tmp, ft_strlen(tmp));
		while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
			write(1, " ", 1);
	}
	else
	{
		while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
			write(1, " ", 1);
		write(1, tmp, ft_strlen(tmp));
		if (flag_list.precision > flag_list.field)
			return (flag_list.precision);
	}
	free(tmp);
	return (flag_list.field);
}

int		field_no_precision_unsigned(char *str, t_plist flag_list)
{
	int i;

	if (flag_list.flag[0] == 1)
	{
		write(1, str, ft_strlen(str));
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
			write(1, " ", 1);
	}
	else
	{
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
		{
			if (flag_list.flag[1] == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i++;
		}
		write(1, str, ft_strlen(str));
	}
	return (flag_list.field);
}

int		print_unsigned_int(va_list *ap, t_plist flag_list)
{
	unsigned	int	num;
	int				len;
	int				keta;
	char			*str_num;

	len = 0;
	num = va_arg(*ap, unsigned int);
	if (!(str_num = ft_itoa_unsigned(num)))
		return (-1);
	keta = ft_strlen(str_num);
	if (flag_list.flag[1] == 1 && flag_list.precision != -1)
		flag_list.flag[1] = 0;
	if (flag_list.precision == 0 && num == 0)
	{
		free(str_num);
		return (pre_arg_zero(flag_list));
	}
	if (flag_list.field > (int)ft_strlen(str_num))
		len = print_unsigned_int_len(flag_list, keta, str_num);
	else
		len = no_field_unsigned(str_num, flag_list);
	free(str_num);
	return (len);
}
