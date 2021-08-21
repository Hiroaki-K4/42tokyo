/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:20:00 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/21 21:24:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	all_free_mlx(t_info *info)
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

void	free_double_array(char **array)
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

void	map_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_count)
	{
		free(info->map[i]);
		info->map[i] = NULL;
		i++;
	}
	free(info->map);
	info->map = NULL;
}

void	all_free(t_info *info, char *message)
{
	write(1, message, ft_strlen(message));
	if (info->col_count)
		free(info->col_count);
	if (info->map)
		map_free(info);
	all_free_mlx(info);
	exit(0);
}
