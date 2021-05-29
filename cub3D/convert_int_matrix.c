/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:58:03 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/29 17:33:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void map_not_srrounded_check(t_info *info)
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
			write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
			i++;
		}
		if (j == 0 || j == info->cub_list.map_x - 1)
		{
			if (last_no_wall_col != -1)
			{
				printf("Error\n");
				printf("Map file is wrong\n");
				exit(1);
			}
		}
		else
		{
			if (first_no_wall_col == 0 || last_no_wall_col == info->cub_list.map_y - 1)
			{
				printf("Error\n");
				printf("Map file is wrong\n");
				exit(1);
			}
			if (first_no_wall_col != -1)
			{
				if (info->cub_list.map_matrix[first_no_wall_col - 1][j] != 1 || info->cub_list.map_matrix[last_no_wall_col + 1][j] != 1)
				{
					printf("Error\n");
					printf("Map file is wrong\n");
					exit(1);
				}
			}
		}
		write(1, "\n", 1);
		j++;
		// printf("col_first: %d col_last: %d\n", first_no_wall_col, last_no_wall_col);
	}
}

void map_space_check(t_info *info)
{
	// int i;
	// int j;

	// i = 0;
	// while (i < info->cub_list.map_y)
	// {
	// 	j = 0;
	// 	while (j < info->cub_list.map_x)
	// 	{
	// 		if (info->cub_list.map_matrix[i][j] == 5)
	// 		{
	// 			if (i == 0)
	// 			{
	// 				if (j == 0)
	// 				{
	// 					if (info->cub_list.map_matrix[i][j + 1] ==)
	// 				}
	// 				else if (j == info->cub_list.map_x - 1)
	// 				{

	// 				}
	// 				else
	// 				{
						
	// 				}
	// 			}
	// 			else if (i == info->cub_list.map_y - 1)
	// 			{
					
	// 			}
	// 			else
	// 			{
					
	// 			}
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
}

int convert_int_matrix(t_info *info)
{
	int i;
	int j;
	int first_no_wall_row;
	int last_no_wall_row;
	
	if (!(info->cub_list.map_matrix = (int **)malloc(sizeof(int *) * (info->cub_list.map_y))))
		return (-1);
	i = 0;
	while (i < info->cub_list.map_y)
	{
		if (!(info->cub_list.map_matrix[i] = (int *)malloc(sizeof(int) * (info->cub_list.map_x))))
			return (-1);
		i++;
	}
	i = 0;
	printf("mapx: %d mapy: %d\n", info->cub_list.map_x, info->cub_list.map_y);
	while (i < info->cub_list.map_y)
	{
		// if (ft_strchr(info->cub_list.map[i], ' ') != NULL)
		// {
		// 	printf("Error\n");
		// 	printf("Map includes the space\n");
		// 	exit(1);
		// }
		j = 0;
		first_no_wall_row = 2147483647;
		last_no_wall_row = -1;
		if (ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
		{
			while (j < ft_strlen(info->cub_list.map[i]))
			{
				if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
				{
					info->posX = (double)i + 0.5;
					info->posY = (double)j + 0.5;
					info->cub_list.init_pos_count++;
				}
				if (info->cub_list.map[i][j] == 'N')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = -1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = 0.66;
				}
				else if (info->cub_list.map[i][j] == 'S')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = -0.66;
				}
				else if (info->cub_list.map[i][j] == 'W')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = -1.0;
					info->planeX = -0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == 'E')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = 1.0;
					info->planeX = 0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == ' ')
					info->cub_list.map_matrix[i][j] = 5;
				else
					info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
				// if (info->cub_list.map_matrix[i][j] == 0 || info->cub_list.map_matrix[i][j] == 2)
				// {
				// 	if (j < first_no_wall_row)
				// 		first_no_wall_row = j;
				// 	if (j > last_no_wall_row)
				// 		last_no_wall_row = j;
				// }
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
			while (j < info->cub_list.map_x)
			{
				info->cub_list.map_matrix[i][j] = 5;
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		else
		{
			while (j < info->cub_list.map_x)
			{
				if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
				{
					info->posX = (double)i + 0.5;
					info->posY = (double)j + 0.5;
					info->cub_list.init_pos_count++;
				}
				if (info->cub_list.map[i][j] == 'N')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = -1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = 0.66;
				}
				else if (info->cub_list.map[i][j] == 'S')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = -0.66;
				}
				else if (info->cub_list.map[i][j] == 'W')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = -1.0;
					info->planeX = -0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == 'E')
				{	
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = 1.0;
					info->planeX = 0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == ' ')
					info->cub_list.map_matrix[i][j] = 5;
				else
					info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
				// if (info->cub_list.map_matrix[i][j] == 0 || info->cub_list.map_matrix[i][j] == 2)
				// {
				// 	if (j < first_no_wall_row)
				// 		first_no_wall_row = j;
				// 	if (j > last_no_wall_row)
				// 		last_no_wall_row = j;
				// }
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		if (i == 0 || i == info->cub_list.map_y - 1)
		{
			if (last_no_wall_row != -1)
			{
				printf("Error\n");
				printf("Map file is wrong\n");
				exit(1);
			}
		}
		else
		{
			if (first_no_wall_row == 0 || last_no_wall_row == info->cub_list.map_x - 1)
			{
				printf("Error\n");
				printf("Map file is wrong\n");
				exit(1);
			}
			if (first_no_wall_row != -1)
			{
				if (info->cub_list.map_matrix[i][first_no_wall_row - 1] != 1 || info->cub_list.map_matrix[i][last_no_wall_row + 1] != 1)
				{
					printf("Error\n");
					printf("Map file is wrong\n");
					exit(1);
				}
			}
		}
		// printf("fisrt: %d last: %d\n", first_no_wall_row, last_no_wall_row);
		write(1, "\n", 1);
		i++;
	}
	map_not_srrounded_check(info);
	map_space_check(info);
	if (info->cub_list.init_pos_count != 1)
	{
		printf("Error\n");
		printf("Map file is wrong\n");
		exit(1);
	}
	return (0);
}