/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:41:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/22 15:42:01 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pre_arg_zero_pointer(t_plist flag_list, int i, int len)
{
	if (flag_list.field > 2)
	{
		if (flag_list.flag[0] == 1)
		{
			write(1, "0x", 2);
			while ((flag_list.field - 2 - (i++)) > 0)
				write(1, " ", 1);
		}
		else
		{
			while ((flag_list.field - 2 - (i++)) > 0)
				write(1, " ", 1);
			write(1, "0x", 2);
		}
		len = flag_list.field;
	}
	else
	{
		write(1, "0x", 2);
		len = 2;
	}
	return (len);
}

int	print_pointer(va_list *ap, t_plist flag_list)
{
	unsigned	long	num;
	char				*str_num;
	int					keta;
	int					len;
	char				*ans_str;
	int					i;
	int					j;
	int					size;

	num = (unsigned long)va_arg(*ap, void *);
	str_num = ft_itoa_hex_long(num, "0123456789abcdef");
	keta = ft_strlen(str_num);
	size = 0;
	if (flag_list.precision == 0 && num == 0)
		return (pre_arg_zero_pointer(flag_list, 0, 0));
	if (flag_list.flag[0] == 1 && flag_list.flag[1])
		flag_list.flag[1] = 0;
	if (flag_list.precision != -1)
	{
		flag_list.flag[1] = 0;
		if (flag_list.precision > keta)
			size = flag_list.precision + 2;
		else
			size = keta + 2;
	}
	else if (flag_list.flag[1] == 1 && flag_list.field > (keta + 2))
		size = flag_list.field;
	else
		size = keta + 2;
	if (!(ans_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	ans_str[size] = '\0';
	ans_str[0] = '0';
	ans_str[1] = 'x';
	if (size > (keta + 2))
	{
		i = 0;
		while ((size - (keta + 2) - (i++)) > 0)
		{
			ans_str[i + 2] = '0';
			// i++;
		}
		j = 0;
		while (str_num[j])
		{
			ans_str[(i++) + 2] = str_num[j++];
			// i++;
			// j++;
		}
	}
	else
	{
		i = 0;
		while (str_num[i])
		{
			ans_str[i + 2] = str_num[i];
			i++;
		}
	}
	if (flag_list.field > size)
	{
		if (flag_list.flag[0] == 1)
		{
			i = 0;
			while (ans_str[i])
			{
				write(1, &ans_str[i], 1);
				i++;
			}
			i = 0;
			while ((flag_list.field - size - i) > 0)
			{
				write(1, " ", 1);
				i++;
			}
		}
		else
		{
			i = 0;
			while ((flag_list.field - size - i) > 0)
			{
				write(1, " ", 1);
				i++;
			}
			i = 0;
			while (ans_str[i])
			{
				write(1, &ans_str[i], 1);
				i++;
			}
		}
		len = flag_list.field;
	}
	else
	{
		i = 0;
		while (ans_str[i])
		{
			write(1, &ans_str[i], 1);
			i++;
		}
		len = size;
	}
	free(ans_str);
	return (len);
}
