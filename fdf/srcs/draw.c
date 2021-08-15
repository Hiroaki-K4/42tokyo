/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/15 17:11:19 by hkubo            ###   ########.fr       */
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
		while (j < info->col_count[0])
		{
			x_convert = convert_x(info->map[i][j].x, info->map[i][j].y, 30.0);
			// y_convert = convert_y(info->map[i][j].x * 10, info->map[i][j].y * 10, info->map[i][j].z / 10, 30.0);
			y_convert = convert_y(info->map[i][j].x, info->map[i][j].y, 0, 30.0);
			printf("i: %d j: %d x: %d y: %d\n", i, j, x_convert, y_convert);
			if (x_convert >= 0 && y_convert >= 0 && x_convert <= 640 && y_convert <= 480)
				my_mlx_pixel_put(&info->img, x_convert, y_convert, 0x00FF0000);
			info->map[i][j].x = x_convert;
			info->map[i][j].y = y_convert;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			// printf("%d", info->fdf_list[i][j]);
			printf("%d", info->map[i][j].x);
			j++;
		}
		printf("\n");
		i++;
	}
}