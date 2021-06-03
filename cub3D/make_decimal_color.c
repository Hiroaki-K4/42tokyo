/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_decimal_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:55:56 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/03 21:59:23 by hkubo            ###   ########.fr       */
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
	while (i < ft_strlen(hex))
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

char	*make_decimal_color(t_rgb color)
{
	char	*int_to_hex;
	char	*hex;
	char	*red;
	char	*green;
	char	*blue;
	char	*tmp;
	int		ans;

	int_to_hex = ft_itoa_hex(color.red, "0123456789ABCDEF");
	if (!int_to_hex)
		error_process("Malloc failed");
	red = ft_strdup(int_to_hex);
	if (!red)
		error_process("Malloc failed");
	free(int_to_hex);
	int_to_hex = ft_itoa_hex(color.green, "0123456789ABCDEF");
	if (!int_to_hex)
		error_process("Malloc failed");
	green = ft_strdup(int_to_hex);
	if (!green)
		error_process("Malloc failed");
	free(int_to_hex);
	int_to_hex = ft_itoa_hex(color.blue, "0123456789ABCDEF");
	if (!int_to_hex)
		error_process("Malloc failed");
	blue = ft_strdup(int_to_hex);
	if (!blue)
		error_process("Malloc failed");
	free(int_to_hex);
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
