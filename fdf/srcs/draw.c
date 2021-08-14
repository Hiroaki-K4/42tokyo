/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/14 17:38:27 by hkubo            ###   ########.fr       */
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
	// int	y_convert;

	printf("cos: %f sin: %f\n", cos(PI * 30.0 / 180.0), sin(PI * 30.0 / 180.0));
	// draw row line
	y_pos = 0;
	while (y_pos <= info->y_step * info->row_count)
	{
		x_pos = 0;
		while (x_pos <= info->x_step * info->col_count[0])
		{
			x_convert = convert_x(info->x_start + x_pos, info->y_start + y_pos, 30.0);
			// printf("z: %d\n", info->fdf_list[i][j]);
			// y_convert = convert_y(info->x_start + j, info->y_start + i, info->fdf_list[i][j], 30.0);
			// printf("x_convert: %d y_convert: %d\n", x_convert, y_convert);
			my_mlx_pixel_put(&info->img, info->x_start + x_pos, info->y_start + y_pos, 0x00FF0000);
			x_pos++;
		}
		printf("x_end: %d\n", info->x_start + x_pos);
		y_pos += info->y_step;
	}
	// draw col line
	i = 0;
	while (i <= info->x_step * info->col_count[0])
	{
		j = 0;
		while (j <= info->y_step * info->row_count)
		{
			my_mlx_pixel_put(&info->img, info->x_start + i, info->y_start + j, 0x00FF0000);
			j++;
		}
		i += info->x_step;
	}
	printf("x_end: %d\n", info->x_start + i - info->x_step);
	// my_mlx_pixel_put(&info->img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&info->img, 10, 10, 0x00FF0000);
}
