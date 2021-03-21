/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:12:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/21 18:43:53 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_to_num_field(const char *arg, int *i, va_list *ap, t_plist *f_list)
{
	int	num;
	int	j;
	// int	k;

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
		// k = 0;
		j = 0;
		while (ft_isdigit(arg[j]))
		{
			(*i)++;
			// k++;
			j++;
		}
	}
	else
		num = -1;
	return (num);
}

int		str_to_num_pre(const char *arg, int *i, va_list *ap)
{
	int	num;
	int	j;
	int	k;

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
	j = ft_atoi(arg);
	k = 0;
	if (j > 0)
	{
		num = j;
		while (ft_isdigit(arg[k]))
		{
			(*i)++;
			k++;
		}
	}
	else if (j == 0)
	{
		num = 0;
		while (ft_isdigit(arg[k]))
		{
			(*i)++;
			k++;
		}
	}
	else
		num = -1;
	return (num);
}

t_plist	init_plist(void)
{
	t_plist	flag_list;

	flag_list.flag[0] = -1;
	flag_list.flag[1] = -1;
	flag_list.field = -1;
	flag_list.precision = -1;
	flag_list.format = -1;
	return (flag_list);
}
