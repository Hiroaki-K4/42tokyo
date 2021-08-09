/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 21:23:33 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_info(t_info *info)
{
	int	size_x;
	int	size_y;

	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx, &size_x, &size_y);
	info->width = size_x;
	info->height = size_y;
	info->x_start = info->width * 0.1;
	info->x_end = info->width * 0.9;
	info->y_start = info->height * 0.1;
	info->y_end = info->height * 0.9;
	printf("width: %d height: %d\n", info->width, info->height);
	printf("x_start: %d x_end: %d y_start: %d y_end: %d\n", info->x_start, info->x_end, info->y_start, info->y_end);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	read_fdf_file(&info, argv[1]);
	init_info(&info);
	info.win = mlx_new_window(info.mlx, info.width, info.height, "fdf");
	info.img.img = mlx_new_image(info.mlx, info.width, info.height);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel,
			&info.img.line_length, &info.img.endian);
	my_mlx_pixel_put(&info.img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&info.img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(info.mlx, info.win, info.img.img, 0, 0);
	mlx_hook(info.win, 33, 1 << 17, &win_close, &info);
	mlx_hook(info.win, 2, 1L << 0, &key_press, &info);
	mlx_loop(info.mlx);
	draw(&info);
	return (0);
}