/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:05:33 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/25 11:39:04 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_long(unsigned long n)
{
	unsigned long	i;
	int				len;

	i = n / 16;
	if (i != 0)
	{
		len = 2;
		while (i >= 16)
		{
			len++;
			i = i / 16;
		}
	}
	else
		len = 1;
	return (len);
}

int		field_no_precision_sub(long num, char *str, t_plist flag_list, int i)
{
	char *tmp;

	if (num < 0 && flag_list.flag[0] != 1 && flag_list.flag[1] == 1)
	{
		write(1, "-", 1);
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
			write(1, "0", 1);
		num *= -1;
		if (!(tmp = ft_itoa(num)))
			return (-1);
		write(1, tmp, ft_strlen(tmp));
		free(tmp);
	}
	else
	{
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
		{
			if (flag_list.flag[1] == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, str, ft_strlen(str));
	}
	return (0);
}

char	*field_precision_sub(int num, char *str, t_plist flag_list, int i)
{
	int		j;
	char	*tmp;

	if (num < 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 2))))
			return (NULL);
		tmp[0] = '-';
		i = 1;
		while ((flag_list.precision + 2 - (int)ft_strlen(str) - i) > 0)
			tmp[i++] = '0';
		j = 1;
	}
	else
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 1))))
			return (NULL);
		while ((flag_list.precision - (int)ft_strlen(str) - i) > 0)
			tmp[i++] = '0';
		j = 0;
	}
	while ((ft_strlen(str) - j) > 0)
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	return (tmp);
}

int		no_field_int_sub(t_plist flag_list, int num, int digit)
{
	int		len;
	char	*tmp;

	if (!(tmp = ft_itoa(num * (-1))))
		return (-1);
	write(1, "-", 1);
	len = flag_list.precision + 1;
	while (flag_list.precision - (digit++) > 0)
		write(1, "0", 1);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}

int		print_int_len(t_plist flag_list, char *str_num, int keta, int num)
{
	int len;

	if (flag_list.field > (int)ft_strlen(str_num))
	{
		if (flag_list.precision > keta)
			len = field_precision(num, str_num, flag_list, 0);
		else
			len = field_no_precision(num, str_num, flag_list, 0);
	}
	else
		len = no_field_int(num, str_num, flag_list, 0);
	return (len);
}
