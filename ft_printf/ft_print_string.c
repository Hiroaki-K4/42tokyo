/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:44:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/25 09:39:55 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	field_flag_str(char *str, t_plist flag_list, int len)
{
	int i;

	if (flag_list.precision != -1 && flag_list.precision < (int)ft_strlen(str))
	{
		write(1, str, flag_list.precision);
		i = flag_list.precision;
		while (flag_list.field - i > 0)
		{
			write(1, " ", 1);
			i++;
		}
		len = i;
	}
	else
	{
		write(1, str, ft_strlen(str));
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
		{
			write(1, " ", 1);
			i++;
		}
		len = (int)ft_strlen(str) + i;
	}
	return (len);
}

int	no_precision(char *str, t_plist flag_list, int i, int len)
{
	if (flag_list.flag[1] == 1)
	{
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
		{
			write(1, "0", 1);
			i++;
		}
		write(1, str, ft_strlen(str));
		len = (int)ft_strlen(str) + i;
	}
	else
	{
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, str, ft_strlen(str));
		len = (int)ft_strlen(str) + i;
	}
	return (len);
}

int	field_no_flag_str(char *str, t_plist flag_list, int i, int len)
{
	if (flag_list.precision != -1 && flag_list.precision < (int)ft_strlen(str))
	{
		i = flag_list.precision;
		while ((flag_list.field - i) > 0)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, str, flag_list.precision);
		len = i;
	}
	else
		len = no_precision(str, flag_list, i, len);
	return (len);
}

int	no_field_str(char *str, t_plist flag_list)
{
	int len;

	len = 0;
	if (flag_list.precision != -1)
	{
		while (len < flag_list.precision && str[len])
		{
			write(1, &str[len], 1);
			len++;
		}
	}
	else
	{
		write(1, str, ft_strlen(str));
		len = ft_strlen(str);
	}
	return (len);
}

int	print_string(va_list *ap, t_plist flag_list)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	if (flag_list.field != -1)
	{
		if (flag_list.flag[0] == 1)
			len = field_flag_str(str, flag_list, 0);
		else
			len = field_no_flag_str(str, flag_list, 0, 0);
	}
	else
		len = no_field_str(str, flag_list);
	return (len);
}
