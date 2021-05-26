/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_decimal_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:55:56 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/26 17:56:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int hex_to_decimal(char *hex)
{
	int i;
	int j;
	int ans;
	int hex_pow;
	
	ans = 0;
	printf("hex: %s\n", hex);
	i = 0;
	while (i < ft_strlen(hex))
	{
		hex_pow = 1;
		j = 0;
		while (j < i)
		{
			hex_pow *= 16;
			j++;
		}
		printf("hex_pow: %d\n", hex_pow);
		ans += hex_pow * (ft_strchr_place("0123456789ABCDEF", hex[ft_strlen(hex) - 1 - i]));
		i++;
	}
	return (ans);
}

char *make_decimal_color(t_rgb color)
{
	char *hex;
	char *red;
	char *green;
	char *blue;
	char *tmp;
	int ans;
	
	if (!(red = ft_strdup(ft_itoa_hex(color.red, "0123456789ABCDEF"))))
		return (NULL);
	if (!(green = ft_strdup(ft_itoa_hex(color.green, "0123456789ABCDEF"))))
		return (NULL);
	if (!(blue = ft_strdup(ft_itoa_hex(color.blue, "0123456789ABCDEF"))))
		return (NULL);
	if (!(hex = ft_strjoin(red, green)))
		return (NULL);
	if (!(tmp = ft_strdup(hex)))
		return (NULL);
	free(hex);
	if (!(hex = ft_strjoin(tmp, blue)))
		return (NULL);
	free(red);
	free(green);
	free(blue);
	free(tmp);
	ans = hex_to_decimal(hex);
	return (ans);
}