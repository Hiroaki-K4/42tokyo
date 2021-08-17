/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/17 23:01:21 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	convert_x(int x, int y, double angle)
{
	int convert_x;

	convert_x = (int)(x * cos(PI * angle / 180.0) - y * cos(PI * angle / 180.0));
	return (convert_x);
}

int	convert_y(int x, int y, int z, double angle)
{
	int convert_y;

	convert_y = (int)(x * sin(PI * angle / 180.0) + y * sin(PI * angle / 180.0) - z);
	return (convert_y);
}

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

void	move_to_center(t_info *info)
{
	int	i;
	int	j;
	int	x_move;
	int	y_move;

	x_move = (int)((double)(info->width / 2) - (double)((abs(info->coords.xmax) - abs(info->coords.xmin)) / 2));
	// y_move = info->height / 2 - (abs(info->coords.ymax) - abs(info->coords.ymin)) / 2;
	y_move = (int)((double)(info->height / 2) - (double)((abs(info->coords.ymax) - abs(info->coords.ymin)) / 2));
	info->coords.xmin += x_move;
	info->coords.ymin += y_move;
	info->coords.xmax += x_move;
	info->coords.ymax += y_move;
	printf("x_move: %d y_move: %d\n", x_move, y_move);
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			info->map[i][j].x += x_move;
			info->map[i][j].y += y_move;
			// my_mlx_pixel_put(&info->img, info->map[i][j].x, info->map[i][j].y, 0x00FF0000);
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

void	draw_row_line(t_info *info)
{
	int	i;
	int	j;
	int	x;
	double	y;
	double	slope;

	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i] - 1)
		{
			slope = (double)(info->map[i][j + 1].y - info->map[i][j].y) / (double)(info->map[i][j + 1].x - info->map[i][j].x);
			x = info->map[i][j].x;
			y = (double)info->map[i][j].y;
			while (x < info->map[i][j + 1].x)
			{
				y += slope;
				x++;
				// printf("x: %d y_f: %f y_d: %f\n", x, y, round(y));
				// my_mlx_pixel_put(&info->img, x, (int)round(y), 0x00FF0000);
				my_mlx_pixel_put(&info->img, x, (int)round(y), 0x00FFFFFF);
			}
			// printf("x: %f y: %f slope: %f\n", (double)(info->map[i][j + 1].x - info->map[i][j].x), (double)(info->map[i][j + 1].y - info->map[i][j].y), slope);
			j++;
		}
		i++;
	}
}

void	draw_col_line(t_info *info)
{
	int	i;
	int	j;
	int	x;
	double	y;
	double	slope;

	j = 0;
	while (j < info->col_count[0])
	{
		i = 0;
		while (i < info->row_count - 2)
		{
			slope = (double)(info->map[i + 1][j].y - info->map[i][j].y) / (double)(info->map[i][j].x - info->map[i + 1][j].x);
			x = info->map[i][j].x;
			y = (double)info->map[i][j].y;
			while (x > info->map[i + 1][j].x)
			{
				y += slope;
				x--;
				// printf("i: %d j: %d x: %d y_f: %f y_d: %f slope %f\n", i, j, x, y, round(y), slope);
				// my_mlx_pixel_put(&info->img, x, (int)round(y), 0x00FF0000);
				// my_mlx_pixel_put(&info->img, x, (int)round(y), 0x00FFFFFF);
				my_mlx_pixel_put(&info->img, x, (int)round(y), 0x00ffffff);
			}
			// printf("x: %f y: %f slope: %f\n", (double)(info->map[i][j + 1].x - info->map[i][j].x), (double)(info->map[i][j + 1].y - info->map[i][j].y), slope);
			i++;
		}
		j++;
	}
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

void	draw_map(t_info *info)
{
	int	i;
	int	j;
	int	x_convert;
	int	y_convert;

	get_ratio(info);
	get_abs_zmax(info);
	printf("zmax: %d\n", info->coords.zmax);
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			x_convert = convert_x(info->map[i][j].x * info->ratio * 0.7, info->map[i][j].y * info->ratio * 0.7, 30.0);
			if (info->coords.zmax == 0)
				y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7, info->map[i][j].y * info->ratio * 0.7, info->map[i][j].z, 30.0);
			else if (info->coords.zmax > 100)
				y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7, info->map[i][j].y * info->ratio * 0.7, info->map[i][j].z * info->ratio * 0.7 / info->coords.zmax * 20, 30.0);
			else
				y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7, info->map[i][j].y * info->ratio * 0.7, info->map[i][j].z * info->ratio * 0.7 / info->coords.zmax, 30.0);
			// y_convert = convert_y(info->map[i][j].x * info->ratio * 0.7, info->map[i][j].y * info->ratio * 0.7, 0, 30.0);
			// printf("i: %d j: %d x: %d y: %d ratio: %f\n", i, j, x_convert, y_convert, info->ratio);
			info->map[i][j].x = x_convert;
			info->map[i][j].y = y_convert;
			j++;
		}
		i++;
	}
	get_coordinate(info);
	move_to_center(info);
	draw_row_line(info);
	draw_col_line(info);
	printf("xmin: %d ymin: %d xmax: %d ymax: %d\n", info->coords.xmin, info->coords.ymin, info->coords.xmax, info->coords.ymax);
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			// printf("%d", info->fdf_list[i][j]);
			// printf("%d", info->map[i][j].y);
			j++;
		}
		// printf("\n");
		i++;
	}
}