/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_word_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:10:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/08 21:27:49 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_check(t_info *info, char **line_split, char **rgb_split)
{
	int	j;

	rgb_split = ft_split(line_split[1], ',');
	if (rgb_split == NULL)
		error_process("ft_split failed");
	double_array_free(line_split);
	j = 0;
	while (rgb_split[j])
		j++;
	if (j != 3)
		error_process("Color is wrong");
	info->cub_list.floor.red = ft_atoi(rgb_split[0]);
	info->cub_list.floor.green = ft_atoi(rgb_split[1]);
	info->cub_list.floor.blue = ft_atoi(rgb_split[2]);
	double_array_free(rgb_split);
	if (info->cub_list.floor.red < 0 || info->cub_list.floor.green < 0
		|| info->cub_list.floor.blue < 0 || info->cub_list.floor.red > 255
		|| info->cub_list.floor.green > 255 || info->cub_list.floor.blue
		> 255)
		error_process("Color is wrong");
	info->cub_list.floor_dec = make_decimal_color(info->cub_list.floor);
}

int	ceiling_check(t_info *info, char **line_split, char **rgb_split)
{
	int	i;

	i = ft_strcmp("C", line_split[0]);
	if (i == 0)
	{
		rgb_split = ft_split(line_split[1], ',');
		if (rgb_split == NULL)
			error_process("ft_split failed");
		double_array_free(line_split);
		info->cub_list.ceiling.red = ft_atoi(rgb_split[0]);
		info->cub_list.ceiling.green = ft_atoi(rgb_split[1]);
		info->cub_list.ceiling.blue = ft_atoi(rgb_split[2]);
		double_array_free(rgb_split);
		info->cub_list.ceiling_dec = make_decimal_color(info->cub_list.ceiling);
		return (1);
	}
	return (0);
}

int	map_ns_check(t_info *info, char **line_split)
{
	int	i;

	if (line_split[0] == NULL)
	{
		double_array_free(line_split);
		return (1);
	}
	i = ft_strcmp("NO", line_split[0]);
	if (i == 0)
	{
		info->cub_list.n_texture = ft_strdup(line_split[1]);
		double_array_free(line_split);
		return (1);
	}
	i = ft_strcmp("SO", line_split[0]);
	if (i == 0)
	{
		info->cub_list.s_texture = ft_strdup(line_split[1]);
		double_array_free(line_split);
		return (1);
	}
	return (0);
}

int	map_we_check(t_info *info, char **line_split)
{
	int	i;

	i = ft_strcmp("WE", line_split[0]);
	if (i == 0)
	{
		info->cub_list.w_texture = ft_strdup(line_split[1]);
		double_array_free(line_split);
		return (1);
	}
	i = ft_strcmp("EA", line_split[0]);
	if (i == 0)
	{
		info->cub_list.e_texture = ft_strdup(line_split[1]);
		double_array_free(line_split);
		return (1);
	}
	// i = ft_strcmp("S", line_split[0]);
	// if (i == 0)
	// {
	// 	info->cub_list.sprite = ft_strdup(line_split[1]);
	// 	double_array_free(line_split);
	// 	info->cub_list.sprite_flag = 1;
	// 	return (1);
	// }
	return (0);
}
