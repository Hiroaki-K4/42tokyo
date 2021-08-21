/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:11:12 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/21 21:21:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_row_line_core(t_info *info, int i, int j)
{
	int		x;
	double	y;
	double	slope;

	slope = (double)(info->map[i][j + 1].y - info->map[i][j].y)
		/ (double)(info->map[i][j + 1].x - info->map[i][j].x);
	x = info->map[i][j].x;
	y = (double)info->map[i][j].y;
	while (x < info->map[i][j + 1].x)
	{
		y += slope;
		x++;
		if (x < 0 || x > info->width || (int)round(y) < 0
			|| (int)round(y) > info->height)
			all_free(info, "[End process] draw_row_line\n");
		my_mlx_pixel_put(&info->img, x, (int)round(y), info->map[i][j].color);
	}
}

void	draw_row_line(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->row_count - 1)
	{
		j = 0;
		while (j < info->col_count[i] - 1)
		{
			draw_row_line_core(info, i, j);
			j++;
		}
		i++;
	}
}

void	draw_col_line_core(t_info *info, int i, int j)
{
	int		x;
	double	y;
	double	slope;

	slope = (double)(info->map[i + 1][j].y - info->map[i][j].y)
		/ (double)(info->map[i][j].x - info->map[i + 1][j].x);
	x = info->map[i][j].x;
	y = (double)info->map[i][j].y;
	while (x > info->map[i + 1][j].x)
	{
		y += slope;
		x--;
		if (x < 0 || x > info->width || (int)round(y) < 0
			|| (int)round(y) > info->height)
			all_free(info, "[End process] draw_col_line\n");
		my_mlx_pixel_put(&info->img, x, (int)round(y), info->map[i][j].color);
	}
}

void	draw_col_line(t_info *info)
{
	int		i;
	int		j;

	j = 0;
	while (j < info->col_count[0])
	{
		i = 0;
		while (i < info->row_count - 2)
		{
			draw_col_line_core(info, i, j);
			i++;
		}
		j++;
	}
}
