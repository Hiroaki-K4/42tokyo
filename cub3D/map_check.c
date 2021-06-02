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