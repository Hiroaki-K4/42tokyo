/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:31:12 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 17:37:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		digit_size(unsigned int number)
{
	int		count;

	count = 0;
	if (number == 0)
		count++;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa_unsigned(unsigned int n)
{
	int		len;
	char	*ans;

	len = digit_size(n);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	len--;
	while (len >= 0)
	{
		ans[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (ans);
}

int				get_len(unsigned int n)
{
	int i;
	int len;
	
	i = n / 16;
	if (i != 0)
	{
		len = 0;
		while (i > 16)
		{
			len++;
			i = i / 16;
		}
	}
	else
		len = 1;
	return (len);
}

char			*ft_itoa_hex(unsigned int n)
{
	int len;
	char *tmp = "aaa";

	printf("number: %u\n", n);
	len = get_len(n);
	printf("hex_len: %d\n", len);
	return (tmp);
}