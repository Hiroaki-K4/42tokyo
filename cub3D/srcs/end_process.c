/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:04:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/16 23:05:32 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_process(t_info *info, char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	all_free(info);
	exit(1);
}

void	all_free_core(t_info *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
}

void	all_free(t_info *info)
{
	if (info->buf)
		int_double_array_free(info->buf, info->cub_list.height);
	if (info->texture)
		int_double_array_free(info->texture, 4);
	if (info->cub_list.map_matrix)
		int_double_array_free(info->cub_list.map_matrix, info->cub_list.map_y);
	if (info->cub_list.map)
		double_array_free(info->cub_list.map);
	if (info->cub_list.n_texture)
		free(info->cub_list.n_texture);
	if (info->cub_list.s_texture)
		free(info->cub_list.s_texture);
	if (info->cub_list.e_texture)
		free(info->cub_list.e_texture);
	if (info->cub_list.w_texture)
		free(info->cub_list.w_texture);
	all_free_core(info);
	exit(0);
}

void	int_double_array_free(int **array, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (array[i])
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
		if (array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
	array = NULL;
}
