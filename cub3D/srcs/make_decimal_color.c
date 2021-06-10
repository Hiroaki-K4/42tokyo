/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_decimal_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:55:56 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/10 22:40:30 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hex_to_decimal(char *hex)
{
	int	i;
	int	j;
	int	ans;
	int	hex_pow;

	ans = 0;
	i = 0;
	while (i < (int)ft_strlen(hex))
	{
		hex_pow = 1;
		j = 0;
		while (j < i)
		{
			hex_pow *= 16;
			j++;
		}
		ans += hex_pow * (ft_strchr_place("0123456789ABCDEF",
					hex[ft_strlen(hex) - 1 - i]));
		i++;
	}
	return (ans);
}

char	*convert_color(int color)
{
	char	*int_to_hex;
	char	*rgb;

	int_to_hex = ft_itoa_hex(color, "0123456789ABCDEF");
	if (!int_to_hex)
		error_process("Malloc failed");
	rgb = ft_strdup(int_to_hex);
	if (!rgb)
		error_process("Malloc failed");
	free(int_to_hex);
	return (rgb);
}

int	unite_color(char *red, char *green, char *blue)
{
	char	*hex;
	char	*tmp;
	int		ans;

	hex = ft_strjoin(red, green);
	if (!hex)
		error_process("Malloc failed");
	tmp = ft_strdup(hex);
	if (!tmp)
		error_process("Malloc failed");
	free(hex);
	hex = ft_strjoin(tmp, blue);
	if (!hex)
		error_process("Malloc failed");
	free(red);
	free(green);
	free(blue);
	free(tmp);
	ans = hex_to_decimal(hex);
	free(hex);
	return (ans);
}

int	make_decimal_color(t_rgb color)
{
	char	*red;
	char	*green;
	char	*blue;
	int		ans;

	red = convert_color(color.red);
	green = convert_color(color.green);
	blue = convert_color(color.blue);
	ans = unite_color(red, green, blue);
	return (ans);
}
