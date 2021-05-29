/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:58:03 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/29 14:01:35 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int convert_int_matrix(t_info *info)
{
	int i;
	int j;
	int first_zero;
	int last_zero;
	
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
	while (i < info->cub_list.map_y)
	{
		// if (ft_strchr(info->cub_list.map[i], ' ') != NULL)
		// {
		// 	printf("Error\n");
		// 	printf("Map includes the space\n");
		// 	exit(1);
		// }
		j = 0;
		first_zero = 2147483647;
		last_zero = 0;
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
				if (info->cub_list.map_matrix[i][j] == 0)
				{
					if (j < first_zero)
						first_zero = j;
					if (j > last_zero)
						last_zero = j;
					printf("fisrt: %d last: %d\n", first_zero, last_zero);
				}
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
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		write(1, "\n", 1);
		i++;
	}
	if (info->cub_list.init_pos_count != 1)
	{
		printf("Error\n");
		printf("Map file is wrong\n");
		exit(1);
	}
	return (0);
}