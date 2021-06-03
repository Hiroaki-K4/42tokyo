/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_space_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 22:06:40 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/03 11:29:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	first_row_check(t_info *info, int i, int j)
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

void	last_row_check(t_info *info, int i, int j)
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

void	middle_row_check(t_info *info, int i, int j)
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

void	map_space_check(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		while (j < info->cub_list.map_x)
		{
			if (info->cub_list.map_matrix[i][j] == 5)
			{
				if (i == 0)
					first_row_check(info, i, j);
				else if (i == info->cub_list.map_y - 1)
					last_row_check(info, i, j);
				else
					middle_row_check(info, i, j);
			}
			j++;
		}
		i++;
	}
}
