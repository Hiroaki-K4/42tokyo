/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:04:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/16 22:08:01 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_process(char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	exit(1);
}

void	all_free(t_info *info)
{
	int_double_array_free(info->buf, info->cub_list.height);
	int_double_array_free(info->texture, 4);
	int_double_array_free(info->cub_list.map_matrix, info->cub_list.map_y);
	double_array_free(info->cub_list.map);
	free(info->cub_list.n_texture);
	free(info->cub_list.s_texture);
	free(info->cub_list.e_texture);
	free(info->cub_list.w_texture);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	exit(0);
}

void	int_double_array_free(int **array, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (!array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
	array = NULL;
}

void	double_array_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
	array = NULL;
}
