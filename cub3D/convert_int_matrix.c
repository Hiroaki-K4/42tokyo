/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:58:03 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/01 22:05:17 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_not_srrounded_check(t_info *info)
{
	int i;
	int j;
	int first_no_wall_col;
	int last_no_wall_col;

	j = 0;
	while (j < info->cub_list.map_x)
	{
		first_no_wall_col = 2147483647;
		last_no_wall_col = -1;
		i = 0;
		while (i < info->cub_list.map_y)
		{
			if (info->cub_list.map_matrix[i][j] == 0 || info->cub_list.map_matrix[i][j] == 2)
			{
				if (i < first_no_wall_col)
					first_no_wall_col = i;
				if (i > last_no_wall_col)
					last_no_wall_col = i;
			}
			i++;
		}
		if (last_no_wall_col == -1)
		{
			j++;
			continue;
		}
		else if (j == 0 || j == info->cub_list.map_x - 1)
			error_process("Map file is wrong");
		else
		{
			if (first_no_wall_col == 0 || last_no_wall_col == info->cub_list.map_y - 1)
				error_process("Map file is wrong");
			if (first_no_wall_col != -1)
			{
				if (info->cub_list.map_matrix[first_no_wall_col - 1][j] != 1 || info->cub_list.map_matrix[last_no_wall_col + 1][j] != 1)
					error_process("Map file is wrong");
			}
		}
		j++;
	}
}

void	map_space_check(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		while (j < info->cub_list.map_x)
		{
			if (info->cub_list.map_matrix[i][j] == 5)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						if (info->cub_list.map_matrix[i][j + 1] == 0 || info->cub_list.map_matrix[i + 1][j] == 0 || info->cub_list.map_matrix[i][j + 1] == 2 || info->cub_list.map_matrix[i + 1][j] == 2)
							error_process("Map file is wrong");
					}
					else if (j == info->cub_list.map_x - 1)
					{
						if (info->cub_list.map_matrix[i][j - 1] == 0 || info->cub_list.map_matrix[i + 1][j] == 0 || info->cub_list.map_matrix[i][j - 1] == 2 || info->cub_list.map_matrix[i + 1][j] == 2)
							error_process("Map file is wrong");
					}
					else
					{
						if (info->cub_list.map_matrix[i][j - 1] == 0 || info->cub_list.map_matrix[i + 1][j] == 0 || info->cub_list.map_matrix[i][j + 1] == 0 || info->cub_list.map_matrix[i][j - 1] == 2 || info->cub_list.map_matrix[i + 1][j] == 2 || info->cub_list.map_matrix[i][j + 1] == 2)
							error_process("Map file is wrong");
					}
				}
				else if (i == info->cub_list.map_y - 1)
				{
					if (j == 0)
					{
						if (info->cub_list.map_matrix[i][j + 1] == 0 || info->cub_list.map_matrix[i - 1][j] == 0 || info->cub_list.map_matrix[i][j + 1] == 2 || info->cub_list.map_matrix[i - 1][j] == 2)
							error_process("Map file is wrong");
					}
					else if (j == info->cub_list.map_x - 1)
					{
						if (info->cub_list.map_matrix[i][j - 1] == 0 || info->cub_list.map_matrix[i - 1][j] == 0 || info->cub_list.map_matrix[i][j - 1] == 2 || info->cub_list.map_matrix[i - 1][j] == 2)
							error_process("Map file is wrong");
					}
					else
					{
						if (info->cub_list.map_matrix[i][j - 1] == 0 || info->cub_list.map_matrix[i - 1][j] == 0 || info->cub_list.map_matrix[i][j + 1] == 0 || info->cub_list.map_matrix[i][j - 1] == 2 || info->cub_list.map_matrix[i - 1][j] == 2 || info->cub_list.map_matrix[i][j + 1] == 2)
							error_process("Map file is wrong");
					}
				}
				else
				{
					if (j == 0)
					{
						if (info->cub_list.map_matrix[i][j + 1] == 0 || info->cub_list.map_matrix[i + 1][j] == 0 || info->cub_list.map_matrix[i - 1][j] == 0 || info->cub_list.map_matrix[i][j + 1] == 2 || info->cub_list.map_matrix[i + 1][j] == 2 || info->cub_list.map_matrix[i - 1][j] == 2)
							error_process("Map file is wrong");
					}
					else if (j == info->cub_list.map_x - 1)
					{
						if (info->cub_list.map_matrix[i][j - 1] == 0 || info->cub_list.map_matrix[i + 1][j] == 0 || info->cub_list.map_matrix[i - 1][j] == 0 || info->cub_list.map_matrix[i][j - 1] == 2 || info->cub_list.map_matrix[i + 1][j] == 2 || info->cub_list.map_matrix[i - 1][j] == 2)
							error_process("Map file is wrong");
					}
					else
					{
						if (info->cub_list.map_matrix[i][j - 1] == 0 || info->cub_list.map_matrix[i + 1][j] == 0 || info->cub_list.map_matrix[i][j + 1] == 0 || info->cub_list.map_matrix[i - 1][j] == 0 || info->cub_list.map_matrix[i][j - 1] == 2 || info->cub_list.map_matrix[i + 1][j] == 2 || info->cub_list.map_matrix[i][j + 1] == 2 || info->cub_list.map_matrix[i - 1][j] == 2)
							error_process("Map file is wrong");
					}
				}
			}
			j++;
		}
		i++;
	}
}

void	init_dir_plane(t_info *info, double x, double y, int type)
{
	info->dirX = 0.0;
	info->dirY = 0.0;
	info->planeX = 0.0;
	info->planeY = 0.0;
	if (type == 0)
	{
		info->dirX = x;
		info->planeY = y;
	}
	else if (type == 1)
	{
		info->dirX = x;
		info->planeY = y;
	}
	else if (type == 2)
	{
		info->dirY = x;
		info->planeX = y;
	}
	else if (type == 3)
	{
		info->dirY = x;
		info->planeX = y;
	}
}

void	init_setting(t_info *info, int i, int j)
{
	if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
	{
		info->posX = (double)i + 0.5;
		info->posY = (double)j + 0.5;
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
	int i;

	if (!(info->cub_list.map_matrix = (int **)malloc(sizeof(int *) * (info->cub_list.map_y))))
		error_process("Malloc failed");
	i = 0;
	while (i < info->cub_list.map_y)
	{
		if (!(info->cub_list.map_matrix[i] = (int *)malloc(sizeof(int) * (info->cub_list.map_x))))
			error_process("Malloc failed");
		i++;
	}
}

void set_nowall_edge(t_info *info, int i, int j, int max)
{
	while (j < max)
	{
		init_setting(info, i, j);
		if (info->cub_list.map_matrix[i][j] == 0 || info->cub_list.map_matrix[i][j] == 2)
		{
			if (j < info->cub_list.first_no_wall_row)
				info->cub_list.first_no_wall_row = j;
			if (j > info->cub_list.last_no_wall_row)
				info->cub_list.last_no_wall_row = j;
		}
		j++;
	}
	if (ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
	{
		while (j < info->cub_list.map_x)
			info->cub_list.map_matrix[i][j++] = 5;
	}
}



int		convert_int_matrix(t_info *info)
{
	int i;
	int j;

	map_malloc(info);
	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		info->cub_list.first_no_wall_row = 2147483647;
		info->cub_list.last_no_wall_row = -1;
		if (ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
			set_nowall_edge(info, i, j, ft_strlen(info->cub_list.map[i]));
		else
			set_nowall_edge(info, i, j, info->cub_list.map_x);
		if (info->cub_list.last_no_wall_row == -1)
		{
			i++;
			continue;
		}
		else if (i == 0 || i == info->cub_list.map_y - 1)
			error_process("Map file is wrong");
		else
		{
			if (info->cub_list.first_no_wall_row == 0 || info->cub_list.last_no_wall_row == info->cub_list.map_x - 1)
				error_process("Map file is wrong");
			if (info->cub_list.last_no_wall_row != -1 && (info->cub_list.map_matrix[i][info->cub_list.first_no_wall_row - 1] != 1 || info->cub_list.map_matrix[i][info->cub_list.last_no_wall_row + 1] != 1))
			{
				// if (info->cub_list.map_matrix[i][info->cub_list.first_no_wall_row - 1] != 1 || info->cub_list.map_matrix[i][info->cub_list.last_no_wall_row + 1] != 1)
				error_process("Map file is wrong");
			}
		}
		i++;
	}
	map_not_srrounded_check(info);
	map_space_check(info);
	if (info->cub_list.init_pos_count != 1)
		error_process("Map file is wrong");
	return (0);
}