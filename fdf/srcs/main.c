/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/22 22:03:44 by hkubo            ###   ########.fr       */
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
	if (max == 0)
		all_free(info, "get_x_step\n");
	info->x_step = (info->x_end - info->x_start) / max;
}

void	init_info(t_info *info)
{
	int	size_x;
	int	size_y;

	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx, &size_x, &size_y);
	info->width = size_x;
	info->height = size_y;
	info->x_start = info->width * 0.3;
	info->x_end = info->width * 0.8;
	get_x_step(info);
	info->y_start = 0.1;
	info->y_end = info->height * 0.6;
	info->y_step = (info->y_end - info->y_start) / info->row_count;
}

void	insert_null(t_info *info)
{
	info->map = NULL;
	info->win = NULL;
	info->img.img = NULL;
	info->mlx = NULL;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		insert_null(&info);
		printf("read_fdf_file\n");
		read_fdf_file(&info, argv[1]);
		printf("init_info\n");
		init_info(&info);
		printf("win\n");
		info.win = mlx_new_window(info.mlx, info.width, info.height, "FDF");
		printf("img.img\n");
		info.img.img = mlx_new_image(info.mlx, info.width, info.height);
		printf("img.addr\n");
		info.img.addr = mlx_get_data_addr(info.img.img,
				&info.img.bits_per_pixel, &info.img.line_length,
				&info.img.endian);
		printf("draw_map_first\n");
		draw_map(&info);
		mlx_put_image_to_window(info.mlx, info.win, info.img.img, 0, 0);
		mlx_hook(info.win, 33, 1 << 17, &win_close, &info);
		mlx_hook(info.win, 2, 1L << 0, &key_press, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}
