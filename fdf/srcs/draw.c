/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:38:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/11 20:53:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	draw(t_info *info)
{
	int	i;
	int	j;

	// draw row line
	i = 0;
	while (info->y_start + i <= info->y_start + info->y_step * info->row_count)
	{
		j = 0;
		while (info->x_start + j <= info->x_start + info->x_step * info->col_count[0])
		{
			my_mlx_pixel_put(&info->img, info->x_start + j, info->y_start + i, 0x00FF0000);
			j++;
		}
		printf("x_end: %d\n", info->x_start + j);
		i += info->y_step;
	}
	// draw col line
	i = 0;
	while (info->x_start + i <= info->x_start + info->x_step * info->col_count[0])
	{
		j = 0;
		while (info->y_start + j <= info->y_start + info->y_step * info->row_count)
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
