/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:15:47 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/21 18:17:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordinate(t_info *info)
{
	int	i;
	int	j;

	info->coords.xmin = info->width;
	info->coords.ymin = info->height;
	info->coords.xmax = 0;
	info->coords.ymax = 0;
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			if (info->coords.xmin > info->map[i][j].x)
				info->coords.xmin = info->map[i][j].x;
			if (info->coords.ymin > info->map[i][j].y)
				info->coords.ymin = info->map[i][j].y;
			if (info->coords.xmax < info->map[i][j].x)
				info->coords.xmax = info->map[i][j].x;
			if (info->coords.ymax < info->map[i][j].y)
				info->coords.ymax = info->map[i][j].y;
			j++;
		}
		i++;
	}
}

void	get_ratio(t_info *info)
{
	double	x_ratio;
	double	y_ratio;

	x_ratio = info->width / info->col_count[0];
	y_ratio = info->height / (info->row_count - 1);
	if (x_ratio <= y_ratio)
		info->ratio = x_ratio;
	else
		info->ratio = y_ratio;
}

void	get_abs_zmax(t_info *info)
{
	int	i;
	int	j;

	info->coords.zmax = 0;
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			if (info->coords.zmax < abs(info->map[i][j].z))
				info->coords.zmax = abs(info->map[i][j].z);
			j++;
		}
		i++;
	}
}
