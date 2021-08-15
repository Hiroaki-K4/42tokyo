/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/15 21:26:19 by hkubo            ###   ########.fr       */
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

	convert_y = (int)(x * sin(PI * angle / 180.0) + y * sin(PI * angle / 180.0) + z);
	return (convert_y);
}

void	draw(t_info *info)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;
	int	x_convert;
	int	y_convert;

	printf("cos: %f sin: %f\n", cos(PI * 30.0 / 180.0), sin(PI * 30.0 / 180.0));
	// draw row line
	i = 0;
	y_pos = 0;
	while (y_pos <= info->y_step * info->row_count)
	{
		j = 0;
		x_pos = 0;
		while (x_pos <= info->x_step * info->col_count[0])
		{
			x_convert = convert_x(info->x_start + x_pos, info->y_start + y_pos, 30.0) + info->width * 0.2;
			// printf("z: %d\n", info->fdf_list[i][j]);
			y_convert = convert_y(info->x_start + x_pos, info->y_start + y_pos, 0, 30.0) - info->height * 0.1;
			if (y_pos == 0)
				printf("y_start: %d convert: %d\n", info->y_start, y_convert);
			// printf("x_convert: %d y_convert: %d\n", x_convert, y_convert);
			// my_mlx_pixel_put(&info->img, info->x_start + x_pos, info->y_start + y_pos, 0x00FF0000);
			my_mlx_pixel_put(&info->img, x_convert, y_convert, 0x00FF0000);
			x_pos++;
			if (x_pos == info->x_step * (i + 1))
				j++;
		}
		printf("x_end: %d\n", info->x_start + x_pos);
		y_pos += info->y_step;
		i++;
	}
	// draw col line
	x_pos = 0;
	while (x_pos <= info->x_step * info->col_count[0])
	{
		y_pos = 0;
		while (y_pos <= info->y_step * info->row_count)
		{
			x_convert = convert_x(info->x_start + x_pos, info->y_start + y_pos, 30.0) + info->width * 0.2;
			// printf("z: %d\n", info->fdf_list[i][j]);
			y_convert = convert_y(info->x_start + x_pos, info->y_start + y_pos, 0, 30.0) - info->height * 0.1;
			// my_mlx_pixel_put(&info->img, info->x_start + x_pos, info->y_start + y_pos, 0x00FF0000);
			my_mlx_pixel_put(&info->img, x_convert, y_convert, 0x00FF0000);
			y_pos++;
		}
		x_pos += info->x_step;
	}
	printf("x_end: %d\n", info->x_start + x_pos - info->x_step);
	// my_mlx_pixel_put(&info->img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&info->img, 10, 10, 0x00FF0000);
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

	x_move = info->width / 2 - (abs(info->coords.xmax) - abs(info->coords.xmin)) / 2;
	y_move = info->height / 2 - (abs(info->coords.ymax) - abs(info->coords.ymin)) / 2;
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

void	zoom_map(t_info *info)
{
	int	i;
	int	j;
	int	x_ratio;
	int	y_ratio;
	int	ratio;

	x_ratio = info->width / (info->coords.xmax - info->coords.xmin);
	y_ratio = info->height / (info->coords.ymax - info->coords.ymin);
	if (x_ratio <= y_ratio)
		ratio = x_ratio;
	else
		ratio = y_ratio;
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			info->map[i][j].x *= ratio;
			info->map[i][j].y *= ratio;
			my_mlx_pixel_put(&info->img, info->map[i][j].x, info->map[i][j].y, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	rotate(t_info *info)
{
	int	i;
	int	j;
	int	x_convert;
	int	y_convert;

	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			x_convert = convert_x(info->map[i][j].x, info->map[i][j].y, 30.0);
			// y_convert = convert_y(info->map[i][j].x * 10, info->map[i][j].y * 10, info->map[i][j].z / 10, 30.0);
			y_convert = convert_y(info->map[i][j].x, info->map[i][j].y, 0, 30.0);
			printf("i: %d j: %d x: %d y: %d\n", i, j, x_convert, y_convert);
			// if (x_convert >= 0 && y_convert >= 0 && x_convert <= 640 && y_convert <= 480)
				// my_mlx_pixel_put(&info->img, x_convert, y_convert, 0x00FF0000);
			info->map[i][j].x = x_convert;
			info->map[i][j].y = y_convert;
			j++;
		}
		i++;
	}
	get_coordinate(info);
	move_to_center(info);
	zoom_map(info);
	printf("xmin: %d ymin: %d xmax: %d ymax: %d\n", info->coords.xmin, info->coords.ymin, info->coords.xmax, info->coords.ymax);
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			// printf("%d", info->fdf_list[i][j]);
			printf("%d", info->map[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}