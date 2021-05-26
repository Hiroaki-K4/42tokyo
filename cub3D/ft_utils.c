/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:43:41 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/26 17:48:31 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char			*ft_itoa_hex(unsigned int n, char *arg)
{
	int				len;
	unsigned int	i;
	unsigned int	j;
	char			*ans;

	i = n / 16;
	if (i != 0)
	{
		len = 2;
		while (i > 16)
		{
			len++;
			i = i / 16;
		}
	}
	else
		len = 1;
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	i = n;
	len--;
	if (i == 0)
	{
		ans[0] = '0';
		return (ans);
	}
	while (i > 0)
	{
		j = i % 16;
		ans[len] = arg[j];
		i = i / 16;
		len--;
	}
	return (ans);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strchr_place(const char *str, int c)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(str))
	{
		if (str[j] == c)
			return (j);
		j++;
	}
	return (-1);
}