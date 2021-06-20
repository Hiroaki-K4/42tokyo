/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_word_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:10:23 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/20 13:27:53 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**split_rgb(t_info *info, char **line_split, char **rgb_split,
	char *line)
{
	int	i;

	rgb_split = ft_split(line_split[1], ',');
	if (rgb_split == NULL)
		error_process(info, "ft_split failed");
	if (info->cub_list.line_num != 0)
	{
		double_array_free(rgb_split);
		map_wrong_process(info, line_split, line);
	}
	double_array_free(line_split);
	i = 0;
	while (rgb_split[i])
		i++;
	if (i != 3)
	{
		double_array_free(rgb_split);
		get_next_line(info->cub_list.fd, &line, -1);
		free(line);
		error_process(info, "Color is wrong");
	}
	return (rgb_split);
}

int	floor_check(t_info *info, char **line_split, char **rgb_split, char *line)
{
	int	i;

	i = ft_strcmp("F", line_split[0]);
	if (i == 0)
	{
		if (!line_split[1])
			map_wrong_process(info, line_split, line);
		rgb_split = split_rgb(info, line_split, rgb_split, line);
		info->cub_list.floor.red = ft_atoi(rgb_split[0]);
		info->cub_list.floor.green = ft_atoi(rgb_split[1]);
		info->cub_list.floor.blue = ft_atoi(rgb_split[2]);
		double_array_free(rgb_split);
		check_rgb(info, line, 0);
		if (info->cub_list.f_count++ == 0)
			info->cub_list.floor_dec = make_decimal_color(info,
					info->cub_list.floor);
		return (1);
	}
	return (0);
}

int	ceiling_check(t_info *info, char **line_split, char **rgb_split, char *line)
{
	int	i;

	i = ft_strcmp("C", line_split[0]);
	if (i == 0)
	{
		if (!line_split[1])
			map_wrong_process(info, line_split, line);
		rgb_split = split_rgb(info, line_split, rgb_split, line);
		info->cub_list.ceil.red = ft_atoi(rgb_split[0]);
		info->cub_list.ceil.green = ft_atoi(rgb_split[1]);
		info->cub_list.ceil.blue = ft_atoi(rgb_split[2]);
		double_array_free(rgb_split);
		check_rgb(info, line, 1);
		if (info->cub_list.c_count++ == 0)
			info->cub_list.ceiling_dec = make_decimal_color
				(info, info->cub_list.ceil);
		return (1);
	}
	return (0);
}

int	map_ns_check(t_info *info, char **line_split, char *line)
{
	if (ft_strcmp("NO", line_split[0]) == 0)
	{
		if (!line_split[1])
			map_wrong_process(info, line_split, line);
		if (info->cub_list.n_count++ == 0 && info->cub_list.line_num == 0)
			info->cub_list.n_texture = ft_strdup(line_split[1]);
		if (info->cub_list.line_num != 0)
			map_wrong_process(info, line_split, line);
		double_array_free(line_split);
		return (1);
	}
	if (ft_strcmp("SO", line_split[0]) == 0)
	{
		if (!line_split[1])
			map_wrong_process(info, line_split, line);
		if (info->cub_list.s_count++ == 0 && info->cub_list.line_num == 0)
			info->cub_list.s_texture = ft_strdup(line_split[1]);
		if (info->cub_list.line_num != 0)
			map_wrong_process(info, line_split, line);
		double_array_free(line_split);
		return (1);
	}
	return (0);
}

int	map_we_check(t_info *info, char **line_split, char *line)
{
	if (ft_strcmp("WE", line_split[0]) == 0)
	{
		if (!line_split[1])
			map_wrong_process(info, line_split, line);
		if (info->cub_list.w_count == 0 && info->cub_list.line_num == 0)
			info->cub_list.w_texture = ft_strdup(line_split[1]);
		info->cub_list.w_count++;
		if (info->cub_list.line_num != 0)
			map_wrong_process(info, line_split, line);
		double_array_free(line_split);
		return (1);
	}
	if (ft_strcmp("EA", line_split[0]) == 0)
	{
		if (!line_split[1])
			map_wrong_process(info, line_split, line);
		if (info->cub_list.e_count == 0 && info->cub_list.line_num == 0)
			info->cub_list.e_texture = ft_strdup(line_split[1]);
		info->cub_list.e_count++;
		if (info->cub_list.line_num != 0)
			map_wrong_process(info, line_split, line);
		double_array_free(line_split);
		return (1);
	}
	return (0);
}
