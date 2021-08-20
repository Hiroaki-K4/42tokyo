/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:11:12 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/20 22:28:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_row_line(t_info *info)
{
	int	i;
	int	j;
	int	x;
	double	y;
	double	slope;

	printf("draw_row_line\n");
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
				if (x < 0 || x > info->width || (int)round(y) < 0 || (int)round(y) > info->height)
					exit(1);
				printf("x: %d y: %d\n", x, (int)round(y));
				my_mlx_pixel_put(&info->img, x, (int)round(y), info->map[i][j].color);
			}
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

	printf("draw_col_line\n");
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
				if (x < 0 || x > info->width || (int)round(y) < 0 || (int)round(y) > info->height)
					exit(1);
				my_mlx_pixel_put(&info->img, x, (int)round(y), info->map[i][j].color);
			}
			i++;
		}
		j++;
	}
}