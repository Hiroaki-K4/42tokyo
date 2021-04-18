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

int		str_to_num_field(const char *arg, int *i, va_list *ap, t_plist *f_list)
{
	int	num;
	int	j;

	if (*arg == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0)
		{
			f_list->flag[0] = 1;
			num *= -1;
		}
		(*i)++;
		return (num);
	}
	j = ft_atoi(arg);
	if (j > 0)
	{
		num = j;
		j = 0;
		while (ft_isdigit(arg[j++]))
			(*i)++;
	}
	else
		num = -1;
	return (num);
}

int		str_to_num_pre(const char *arg, int *i, va_list *ap, int k)
{
	int	num;

	if (*arg == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0)
			num = -1;
		(*i)++;
		return (num);
	}
	if (ft_isdigit(arg[0]) == 0)
		return (0);
	num = ft_atoi(arg);
	if (num >= 0)
	{
		while (ft_isdigit(arg[k++]))
			(*i)++;
	}
	else
		num = -1;
	return (num);
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
