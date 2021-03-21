/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:12:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/21 18:13:05 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_to_num(const char *arg, int *i, va_list *ap, int flag, t_plist *flag_list)
{
	int	num;
	int	j;
	int	k;

	if (*arg == '*')
	{
		if (flag == 0)
		{
			num = va_arg(*ap, int);
			if (num < 0)
			{
				flag_list->flag[0] = 1;
				num *= -1;
			}
			(*i)++;
			return (num);
		}
		else
		{
			num = va_arg(*ap, int);
			if (num < 0)
				num = -1;
			(*i)++;
			return (num);
		}
	}
	if (ft_isdigit(arg[0]) == 0 && flag == 1)
		return (0);
	j = ft_atoi(arg);
	if (j > 0)
	{
		num = j;
		k = 0;
		while (ft_isdigit(arg[k]))
		{
			(*i)++;
			k++;
		}
	}
	else if (flag == 1 && j == 0)
	{
		num = 0;
		k = 0;
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