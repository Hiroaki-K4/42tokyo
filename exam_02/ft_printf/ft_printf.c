/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/04 10:55:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_str(const char *arg, int *i)
{
	int	len;

	len = 0;
	while (arg[*i] != '%' && arg[*i])
	{
		write(1, &arg[*i], 1);
		(*i)++;
		len++;
	}
	return (len);
}

int		ft_strchr_place(const char *str, int c, int *i)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(str))
	{
		if (str[j] == c)
		{
			(*i)++;
			return (j);
		}
		j++;
	}
	return (-1);
}

int		output_per(va_list *ap, t_plist flag_list)
{
	int	i;

	i = 0;
	if (flag_list.format == 0)
		i = print_string(ap, flag_list);
	else if (flag_list.format == 1)
		i = print_int(ap, flag_list);
	else if (flag_list.format == 2)
		i = print_hex(ap, flag_list, 0);
	return (i);
}

int		ft_printf_per(const char *arg, int *i, va_list *ap)
{
	int		k;
	t_plist	flag_list;

	(*i)++;
	flag_list = init_plist();
	flag_list.field = str_to_num_field(&arg[*i], i, ap, &flag_list);
	if (arg[*i] == '.')
	{
		(*i)++;
		flag_list.precision = str_to_num_pre(&arg[*i], i, ap, 0);
	}
	flag_list.format = ft_strchr_place("sdx", arg[*i], i);
	k = output_per(ap, flag_list);
	return (k);
}

int		ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		print_len;

	va_start(ap, arg);
	i = 0;
	if (arg == NULL)
		i = -1;
	print_len = 0;
	while (i >= 0 && arg[i])
	{
		if (arg[i] != '%')
			print_len += ft_printf_str(arg, &i);
		else
		{
			j = ft_printf_per(arg, &i, &ap);
			if (j == -1)
				return (-1);
			print_len += j;
		}
	}
	va_end(ap);
	return (print_len);
}
