/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:51:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/03 21:08:28 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_line_check(char **line_split)
{
	int	i;
	int	j;

	i = 0;
	while (line_split[i])
	{
		j = 0;
		while (line_split[i][j])
		{
			if (line_split[i][j] != '0' && line_split[i][j] != '1'
				&& line_split[i][j] != '2' && line_split[i][j] != 'N'
				&& line_split[i][j] != 'S' && line_split[i][j] != 'E'
				&& line_split[i][j] != 'W')
				error_process("Map is wrong");
			j++;
		}
		i++;
	}
	return (0);
}

void	make_string_map(t_info *info, char **tmp, char *map_line)
{
	int	i;

	i = 0;
	while (i < info->cub_list.map_y - 1)
	{
		tmp[i] = (char *)malloc(sizeof(char)
				* (ft_strlen(info->cub_list.map[i]) + 1));
		if (tmp[i] == NULL)
			error_process("Malloc failed");
		ft_strlcpy(tmp[i], info->cub_list.map[i],
			ft_strlen(info->cub_list.map[i]) + 1);
		i++;
	}
	tmp[i] = ft_strdup(map_line);
	if (tmp[i] == NULL)
		error_process("ft_strdup failed");
	free(map_line);
	tmp[i + 1] = NULL;
	if (i > 0)
		double_array_free(info->cub_list.map);
	info->cub_list.map = tmp;
}

void	not_special_word(t_info *info, int count, char **line,
	char **line_split)
{
	char	**tmp;
	char	*map_line;

	double_array_free(line_split);
	if (info->cub_list.line_num != 0 && count - info->cub_list.line_num != 1)
		error_process("Map is wrong");
	info->cub_list.line_num = count;
	info->cub_list.map_y++;
	map_line = ft_strdup(line);
	if (map_line == NULL)
		error_process("ft_strdup failed");
	if (ft_strlen(map_line) > info->cub_list.map_x)
		info->cub_list.map_x = ft_strlen(map_line);
	tmp = (char **)malloc(sizeof(char *) * (info->cub_list.map_y + 1));
	if (tmp == NULL)
		error_process("Malloc failed");
	make_string_map(info, tmp, map_line);
}

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
	i = ft_strcmp("S", line_split[0]);
	if (i == 0)
	{
		info->cub_list.sprite = ft_strdup(line_split[1]);
		double_array_free(line_split);
		info->cub_list.sprite_flag = 1;
		return (1);
	}
	return (0);
}

int	cub_line_check(char **line, int count, t_info *info)
{
	int		i;
	int		j;
	char	**line_split;
	char	**rgb_split;

	line_split = ft_split(line, ' ');
	if (line_split == NULL)
		error_process("ft_split failed");
	i = map_ns_check(info, line_split);
	if (i == 1)
		return (0);
	i = map_we_check(info, line_split);
	if (i == 1)
		return (0);
	i = ft_strcmp("F", line_split[0]);
	if (i == 0)
	{
		floor_check(info, line_split, rgb_split);
		return (0);
	}
	i = ceiling_check(info, line_split, rgb_split);
	if (i == 1)
		return (0);
	if (map_line_check(line_split) == 0)
		not_special_word(info, count, line, line_split);
	return (0);
}
