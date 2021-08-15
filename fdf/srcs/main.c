/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/15 22:24:10 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_x_step(t_info *info)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < info->row_count)
	{
		if (max < info->col_count[i])
			max = info->col_count[i];
		i++;
	}
	info->x_step = (info->x_end - info->x_start) / max;
}

void	init_info(t_info *info)
{
	int	size_x;
	int	size_y;

	info->mlx = mlx_init();
	// mlx_get_screen_size(info->mlx, &size_x, &size_y);
	// size_x = 1920;
	// size_x = 1280;
	size_x = 640;
	// size_y = 1080;
	// size_y = 960;
	size_y = 480;
	info->width = size_x;
	info->height = size_y;
	info->x_start = info->width * 0.3;
	info->x_end = info->width * 0.8;
	get_x_step(info);
	// info->y_start = info->height * 0.2;
	info->y_start = 0.1;
	info->y_end = info->height * 0.6;
	info->y_step = (info->y_end - info->y_start) / info->row_count;
	printf("width: %d height: %d\n", info->width, info->height);
	printf("x_start: %d x_end: %d y_start: %d y_end: %d x_step: %d y_step: %d\n", info->x_start, info->x_end, info->y_start, info->y_end, info->x_step, info->y_step);
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
	// draw(&info);
	draw_map(&info);
	mlx_put_image_to_window(info.mlx, info.win, info.img.img, 0, 0);
	mlx_hook(info.win, 33, 1 << 17, &win_close, &info);
	mlx_hook(info.win, 2, 1L << 0, &key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}