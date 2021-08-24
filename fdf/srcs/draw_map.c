/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/24 22:53:46 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	convert_x(int x, int y, double angle)
{
	int	convert_x;

	convert_x = (int)(x * cos(PI * angle / 180.0) - y
			* cos(PI * angle / 180.0));
	return (convert_x);
}

int	convert_y(int x, int y, int z, double angle)
{
	int	convert_y;

	convert_y = (int)(x * sin(PI * angle / 180.0) + y
			* sin(PI * angle / 180.0) - z);
	return (convert_y);
}

void	move_to_center(t_info *info)
{
	int	i;
	int	j;
	int	x_move;
	int	y_move;

	x_move = (int)((double)(info->width / 2)
			- (double)((abs(info->coords.xmax) - abs(info->coords.xmin)) / 2));
	y_move = (int)((double)(info->height / 2)
			- (double)((abs(info->coords.ymax) - abs(info->coords.ymin)) / 2));
	info->coords.xmin += x_move;
	info->coords.ymin += y_move;
	info->coords.xmax += x_move;
	info->coords.ymax += y_move;
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			info->map[i][j].x += x_move;
			info->map[i][j].y += y_move;
			j++;
		}
		i++;
	}
}

void	convert_xy(int i, int j, t_info *info)
{
	int	x_convert;
	int	y_convert;

	x_convert = convert_x(info->map[i][j].x * info->ratio * 0.7,
			info->map[i][j].y * info->ratio * 0.7, 30.0);
	if (info->coords.zmax == 0)
		y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7,
				info->map[i][j].y * info->ratio * 0.7, info->map[i][j].z, 30.0);
	else if (info->coords.zmax > 100)
		y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7,
				info->map[i][j].y * info->ratio * 0.7, info->map[i][j].z
				* info->ratio * 0.7 / info->coords.zmax * 20, 30.0);
	else
		y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7,
				info->map[i][j].y * info->ratio * 0.7, info->map[i][j].z
				* info->ratio * 0.7 / info->coords.zmax, 30.0);
	info->map[i][j].x = x_convert;
	info->map[i][j].y = y_convert;
}

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	get_ratio(info);
	get_abs_zmax(info);
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			convert_xy(i, j, info);
			j++;
		}
		i++;
	}
	get_coordinate(info);
	move_to_center(info);
	draw_row_line(info);
	draw_col_line(info);
}
