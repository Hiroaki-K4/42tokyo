#include "cub3D.h"

int		map_edge_check(t_info *info, int *i)
{
	if (info->cub_list.last_no_wall_row == -1)
	{
		(*i)++;
		return (0);
	}
	else if (*i == 0 || *i == info->cub_list.map_y - 1)
		error_process("Map file is wrong");
	else
	{
		if (info->cub_list.first_no_wall_row == 0 || info->cub_list.last_no_wall_row == info->cub_list.map_x - 1)
			error_process("Map file is wrong");
		if (info->cub_list.last_no_wall_row != -1 && (info->cub_list.map_matrix[*i][info->cub_list.first_no_wall_row - 1] != 1 || info->cub_list.map_matrix[*i][info->cub_list.last_no_wall_row + 1] != 1))
			error_process("Map file is wrong");
	}
	(*i)++;
	return (0);
}

void	map_not_srrounded_check(t_info *info)
{
	int i;
	int j;

	j = 0;
	while (j < info->cub_list.map_x)
	{
		info->cub_list.first_no_wall_col = 2147483647;
		info->cub_list.last_no_wall_col = -1;
		i = 0;
		while (i < info->cub_list.map_y)
		{
			if (info->cub_list.map_matrix[i][j] == 0 || info->cub_list.map_matrix[i][j] == 2)
			{
				if (i < info->cub_list.first_no_wall_col)
					info->cub_list.first_no_wall_col = i;
				if (i > info->cub_list.last_no_wall_col)
					info->cub_list.last_no_wall_col = i;
			}
			i++;
		}
		if (info->cub_list.last_no_wall_col == -1)
		{
			j++;
			continue;
		}
		else if (j == 0 || j == info->cub_list.map_x - 1)
			error_process("Map file is wrong");
		else
		{
			if (info->cub_list.first_no_wall_col == 0 || info->cub_list.last_no_wall_col == info->cub_list.map_y - 1)
				error_process("Map file is wrong");
			if (info->cub_list.first_no_wall_col != -1)
			{
				if (info->cub_list.map_matrix[info->cub_list.first_no_wall_col - 1][j] != 1 || info->cub_list.map_matrix[info->cub_list.last_no_wall_col + 1][j] != 1)
					error_process("Map file is wrong");
			}
		}
		j++;
	}
}