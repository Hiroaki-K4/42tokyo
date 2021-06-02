#include "cub3D.h"

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
