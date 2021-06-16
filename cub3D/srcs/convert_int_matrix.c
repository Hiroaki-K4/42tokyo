/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:58:03 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/16 22:20:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dir_plane(t_info *info, double x, double y, int type)
{
	info->dir_x = 0.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = 0.0;
	if (type == 0)
	{
		info->dir_x = x;
		info->plane_y = y;
	}
	else if (type == 1)
	{
		info->dir_x = x;
		info->plane_y = y;
	}
	else if (type == 2)
	{
		info->dir_y = x;
		info->plane_x = y;
	}
	else if (type == 3)
	{
		info->dir_y = x;
		info->plane_x = y;
	}
}

void	init_setting(t_info *info, int i, int j)
{
	if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' ||
		info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
	{
		info->pos_x = (double)i + 0.5;
		info->pos_y = (double)j + 0.5;
		info->cub_list.init_pos_count++;
		info->cub_list.map_matrix[i][j] = 0;
	}
	if (info->cub_list.map[i][j] == 'N')
		init_dir_plane(info, -1.0, 0.66, 0);
	else if (info->cub_list.map[i][j] == 'S')
		init_dir_plane(info, 1.0, -0.66, 1);
	else if (info->cub_list.map[i][j] == 'W')
		init_dir_plane(info, -1.0, -0.66, 2);
	else if (info->cub_list.map[i][j] == 'E')
		init_dir_plane(info, 1.0, 0.66, 3);
	else if (info->cub_list.map[i][j] == ' ')
		info->cub_list.map_matrix[i][j] = 5;
	else
		info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
}

void	map_malloc(t_info *info)
{
	int	i;

	info->cub_list.map_matrix = (int **)malloc(sizeof(int *)
			* (info->cub_list.map_y));
	if (info->cub_list.map_matrix == NULL)
		error_process(info, "Malloc failed");
	i = 0;
	while (i < info->cub_list.map_y)
	{
		info->cub_list.map_matrix[i] = (int *)malloc(sizeof(int)
				* (info->cub_list.map_x));
		if (info->cub_list.map_matrix[i] == NULL)
			error_process(info, "Malloc failed");
		i++;
	}
}

void	set_nowall_edge(t_info *info, int i, int j, int max)
{
	while (j < max)
	{
		init_setting(info, i, j);
		if (info->cub_list.map_matrix[i][j] == 0)
		{
			if (j < info->cub_list.f_nowall_row)
				info->cub_list.f_nowall_row = j;
			if (j > info->cub_list.l_nowall_row)
				info->cub_list.l_nowall_row = j;
		}
		j++;
	}
	if ((int)ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
	{
		while (j < info->cub_list.map_x)
			info->cub_list.map_matrix[i][j++] = 5;
	}
}

int	convert_int_matrix(t_info *info)
{
	int	i;
	int	j;

	map_malloc(info);
	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		info->cub_list.f_nowall_row = 2147483647;
		info->cub_list.l_nowall_row = -1;
		if ((int)ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
			set_nowall_edge(info, i, j, ft_strlen(info->cub_list.map[i]));
		else
			set_nowall_edge(info, i, j, info->cub_list.map_x);
		map_edge_check(info, &i);
	}
	map_not_srrounded_check(info);
	map_space_check(info);
	if (info->cub_list.init_pos_count != 1)
		error_process(info, "Map file is wrong");
	return (0);
}
