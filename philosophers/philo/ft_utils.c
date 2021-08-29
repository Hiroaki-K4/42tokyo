/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:43:24 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/29 21:24:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int		digit_size(int number)
{
	int		count;

	count = 0;
	if (number <= 0)
		count++;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		len;
	char	flag;
	char	*ans;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = digit_size(n);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	flag = '+';
	if (n < 0)
	{
		n = n * (-1);
		flag = '-';
	}
	ans[len] = '\0';
	len--;
	while (len >= 0)
	{
		ans[len--] = '0' + (n % 10);
		n = n / 10;
	}
	if (flag == '-')
		ans[0] = '-';
	return (ans);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		flag;
	int		ans;

	flag = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	ans = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = (ans * 10) + (nptr[i] - '0');
		i++;
	}
	ans = ans * flag;
	return (ans);
}
