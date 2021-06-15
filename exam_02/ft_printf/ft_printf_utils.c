/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:12:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/04 11:31:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

t_plist	init_plist(void)
{
	t_plist	flag_list;

	flag_list.field = -1;
	flag_list.precision = -1;
	flag_list.format = -1;
	return (flag_list);
}
