/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:21:45 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 21:37:41 by hkubo            ###   ########.fr       */
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
	my_mlx_pixel_put(&info->img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&info->img, 10, 10, 0x00FF0000);
}

int	win_close(t_info *info)
{
	(void)info;
	exit(1);
	return (0);
}

int	key_press(int key, t_info *info)
{
	(void)info;
	if (key == K_ESC)
		exit(1);
	return (0);
}
