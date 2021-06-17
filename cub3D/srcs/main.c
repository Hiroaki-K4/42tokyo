/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:28:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/17 11:45:16 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->cub_list.height)
	{
		x = 0;
		while (x < info->cub_list.width)
		{
			info->img.data[y * info->cub_list.width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	win_close(t_info *info)
{
	all_free(info);
	return (0);
}

void	read_cub_line(t_info *info, int i, char *path)
{
	int		count;
	char	*line;

	info->cub_list.fd = open(path, O_RDONLY);
	if (info->cub_list.fd == -1)
		error_process(info, strerror(errno));
	info_init(info);
	count = 0;
	while (i > 0)
	{
		i = get_next_line(info->cub_list.fd, &line, 0);
		if (i == -1)
			error_process(info, "get_next_line failed");
		count++;
		cub_line_check(line, count, info);
		free(line);
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;

	insert_null(&info);
	arg_error_check(argc, argv, &info);
	read_cub_line(&info, 1, argv[1]);
	convert_int_matrix(&info);
	info.buf = (int **)malloc(sizeof(int *) * (info.cub_list.height));
	info.texture = (int **)malloc(sizeof(int *) * 4);
	if (info.buf == NULL || info.texture == NULL)
		error_process(&info, "Malloc failed");
	buf_init(&info, 0, 0);
	texture_init(&info, 0, 0);
	load_texture(&info);
	info.win = mlx_new_window(info.mlx, info.cub_list.width,
			info.cub_list.height, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.cub_list.width,
			info.cub_list.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 33, 1 << 17, &win_close, &info);
	mlx_hook(info.win, 2, 1L << 0, &key_press, &info);
	mlx_loop(info.mlx);
}
