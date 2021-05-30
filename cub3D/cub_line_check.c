/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:51:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/30 11:52:14 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int map_line_check(char **line_split)
{
	int i;
	int j;
	
	i = 0;
	while (line_split[i])
	{
		j = 0;
		while (line_split[i][j])
		{
			if (line_split[i][j] != '0' && line_split[i][j] != '1' && line_split[i][j] != '2' 
			&& line_split[i][j] != 'N' && line_split[i][j] != 'S' && line_split[i][j] != 'E' && line_split[i][j] != 'W')
			{
				printf("Error\n");
				printf("Map is wrong\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int cub_line_check(char **line, int count, t_info *info)
{
	int i;
	int j;
	char *map_line;
	char **line_split;
	char **rgb_split;
	char **tmp;
	
	if (!(line_split = ft_split(line, ' ')))
		return (-1);
	if (line_split[0] == NULL)
		return (0);
	else if (i = ft_strcmp("NO", line_split[0]) == 0)
		info->cub_list.n_texture = line_split[1];
	else if (i = ft_strcmp("SO", line_split[0]) == 0)
		info->cub_list.s_texture = line_split[1];
	else if (i = ft_strcmp("WE", line_split[0]) == 0)
		info->cub_list.w_texture = line_split[1];
	else if (i = ft_strcmp("EA", line_split[0]) == 0)
		info->cub_list.e_texture = line_split[1];
	else if (i = ft_strcmp("S", line_split[0]) == 0)
	{
		info->cub_list.sprite = line_split[1];
		info->cub_list.sprite_flag = 1;
	}
	else if (i = ft_strcmp("F", line_split[0]) == 0)
	{
		if (!(rgb_split = ft_split(line_split[1], ',')))
			return (-1);
		j = 0;
		while (rgb_split[j])
			j++;
		if (j != 3)
		{
			printf("Error\n");
			printf("Color is wrong\n");
			exit(1);
		}
		info->cub_list.floor.red = ft_atoi(rgb_split[0]);
		info->cub_list.floor.green = ft_atoi(rgb_split[1]);
		info->cub_list.floor.blue = ft_atoi(rgb_split[2]);
		if (info->cub_list.floor.red < 0 || info->cub_list.floor.green < 0 || info->cub_list.floor.blue < 0 || info->cub_list.floor.red > 255 
			|| info->cub_list.floor.green > 255 || info->cub_list.floor.blue > 255)
		{
			printf("Error\n");
			printf("Color is wrong\n");
			exit(1);
		}
		info->cub_list.floor_dec = make_decimal_color(info->cub_list.floor);
	}
	else if (i = ft_strcmp("C", line_split[0]) == 0)
	{
		if (!(rgb_split = ft_split(line_split[1], ',')))
			return (-1);
		info->cub_list.ceiling.red = ft_atoi(rgb_split[0]);
		info->cub_list.ceiling.green = ft_atoi(rgb_split[1]);
		info->cub_list.ceiling.blue = ft_atoi(rgb_split[2]);
		info->cub_list.ceiling_dec = make_decimal_color(info->cub_list.ceiling);
	}
	else if (map_line_check(line_split) == 0)
	{
		if (info->cub_list.line_num != 0 && count - info->cub_list.line_num != 1)
		{
			printf("Error\n");
			printf("Map is wrong\n");
			exit(1);
		}
		info->cub_list.line_num = count;
		info->cub_list.map_y++;
		if (!(map_line = ft_strdup(line)))
			return (-1);
		if (ft_strlen(map_line) > info->cub_list.map_x)
			info->cub_list.map_x = ft_strlen(map_line);
		if (!(tmp = (char **)malloc(sizeof(char *) * (info->cub_list.map_y))))
		{
			printf("Error\n");
			printf("Malloc failed\n");
			exit(1);
		}
		i = 0;
		while (i < info->cub_list.map_y - 1)
		{
			if (!(tmp[i] = (char **)malloc(sizeof(char) * (ft_strlen(map_line) + 1))))
			{
				printf("Error\n");
				printf("Malloc failed\n");
				exit(1);
			}
			tmp[i] = info->cub_list.map[i];
			i++;
		}
		tmp[i] = map_line;
		free(info->cub_list.map);
		info->cub_list.map = tmp;
	}
	// i = 0;
	// while (line_split[i])
	// {
	// 	free(line_split[i]);
	// 	i++;
	// }
	return (0);
}