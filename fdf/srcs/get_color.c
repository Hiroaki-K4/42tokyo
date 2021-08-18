/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:42:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/18 22:45:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_color_hex(char *color)
{
	int	i;

	if (color[0] != '0' || color[1] != 'x')
		return (-1);
	i = 2;
	while (i < 8)
	{
		if (ft_isdigit(color[i]) != 1 && (color[i] < 'A' || color[i] > 'F') && (color[i] < 'a' || color[i] > 'f'))
			return (-1);
		i++;
	}
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_strchr_place(const char *arg, int c)
{
	int j;

	j = 0;
	while (arg[j])
	{
		if (arg[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

char	*get_color(char *line_split)
{
	char	*color;

	color = ft_strchr(line_split, ',');
	printf("first_color: %s\n", color);
	if (color != NULL)
	{
		if (ft_strlen(color) == 9)
		{
			color++;
			if (check_color_hex(color) == -1)
				exit(1);
		}
		else
		{
			if (ft_strcmp(color, ",0xff") == 0 || ft_strcmp(color, ",0xFF") == 0)
				return ("0xFFFFFF");
			exit(1);
		}
	}
	else
		color = "0xFFFFFF";
	return (color);
}

int	convert_calc(int a, int b, char word)
{
	int	ans;
	int	pos;

	pos = ft_strchr_place("0123456789ABCDEF", word);
	if (pos == -1)
		pos = ft_strchr_place("0123456789abcdef", word);
	if (pos == -1)
		exit(1);
	ans = 1;
	// if (b == 0)
		// return (1);
	while (b > 0)
	{
		ans = ans * a;
		b--;
	}
	ans = ans * pos;
	return (ans);
}

int	convert_hex_to_dec(char *color)
{
	int	i;
	int	dec;

	printf("color: %s\n", color);
	dec = 0;
	i = 2;
	while (i < 8 && color[i])
	{
		dec += convert_calc(16, 7 - i, color[i]);
		i++;
	}
	printf("color: %s dec: %d\n", color, dec);
	return (dec);
}