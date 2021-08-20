/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:42:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/20 21:45:08 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_color_hex(char *color, int len)
{
	int	i;

	if (color[0] != '0' || color[1] != 'x')
		return (-1);
	i = 2;
	while (i < len)
	{
		if (ft_isdigit(color[i]) != 1 && (color[i] < 'A' || color[i] > 'F') && (color[i] < 'a' || color[i] > 'f'))
			return (-1);
		i++;
	}
	return (0);
}

char	*make_restored_color(char *color, int len)
{
	int		i;
	char	*re_color;

	if (color[len - 2] == color[len - 1])
	{
		re_color = (char *)malloc(sizeof(char) * 9);
		if (!re_color)
			exit(1);
		i = 0;
		while (i < len)
		{
			re_color[i] = color[i];
			i++;
		}
		while (i < 8)
		{
			re_color[i] = color[len - 1];
			i++;
		}
		re_color[i] = '\0';
	}
	else
		exit(1);
	return (re_color);
}

char	*get_color(char *line_split)
{
	char	*color;

	color = ft_strchr(line_split, ',');
	if (color != NULL)
	{
		if (ft_strlen(color) == 9)
		{
			color++;
			if (check_color_hex(color, 8) == -1)
				exit(1);
		}
		else if (ft_strlen(color) == 5)
		{
			color++;
			if (check_color_hex(color, 4) == -1)
				exit(1);
			color = make_restored_color(color, 4);
		}
		else if (ft_strlen(color) == 7)
		{
			color++;
			if (check_color_hex(color, 6) == -1)
				exit(1);
			color = make_restored_color(color, 6);
		}
		else
			exit(1);
	}
	else
		color = "0xFFFFFF";
	return (color);
}