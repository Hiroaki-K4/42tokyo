/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:07:53 by hkubo             #+#    #+#             */
/*   Updated: 2020/11/28 19:39:36 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
