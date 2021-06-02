/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 22:06:33 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/02 22:45:49 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_edge_check(t_info *info, int *i)
{
	if (info->cub_list.l_nowall_row == -1)
	{
		(*i)++;
		return (0);
	}
	else if (*i == 0 || *i == info->cub_list.map_y - 1)
		error_process("Map file is wrong");
	else
	{
		if (info->cub_list.f_nowall_row == 0 || info->cub_list.l_nowall_row == info->cub_list.map_x - 1)
			error_process("Map file is wrong");
		if (info->cub_list.l_nowall_row != -1 && (info->cub_list.map_matrix[*i][info->cub_list.f_nowall_row - 1] != 1 || info->cub_list.map_matrix[*i][info->cub_list.l_nowall_row + 1] != 1))
			error_process("Map file is wrong");
	}
	(*i)++;
	return (0);
}

int	col_edge_check(t_info *info, int *j)
{
    if (info->cub_list.l_nowall_col == -1)
    {
        (*j)++;
        return (0);
    }
    if (*j == 0 || *j == info->cub_list.map_x - 1)
        error_process("Map file is wrong");
    else
    {
        if (info->cub_list.f_nowall_col == 0 || info->cub_list.l_nowall_col == info->cub_list.map_y - 1)
            error_process("Map file is wrong");
        if (info->cub_list.f_nowall_col != -1)
        {
            if (info->cub_list.map_matrix[info->cub_list.f_nowall_col - 1][*j] != 1 || info->cub_list.map_matrix[info->cub_list.l_nowall_col + 1][*j] != 1)
                error_process("Map file is wrong");
        }
    }
    (*j)++;
    return (0);
}

void	map_not_srrounded_check(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < info->cub_list.map_x)
	{
		info->cub_list.f_nowall_col = 2147483647;
		info->cub_list.l_nowall_col = -1;
		i = 0;
		while (i < info->cub_list.map_y)
		{
			if (info->cub_list.map_matrix[i][j] == 0 || info->cub_list.map_matrix[i][j] == 2)
			{
				if (i < info->cub_list.f_nowall_col)
					info->cub_list.f_nowall_col = i;
				if (i > info->cub_list.l_nowall_col)
					info->cub_list.l_nowall_col = i;
			}
			i++;
		}
        col_edge_check(info, &j);
	}
}