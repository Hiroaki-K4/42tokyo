/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:28:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/26 18:13:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw(t_info *info)
{
	for (int y = 0; y < info->cub_list.height; y++)
	{
		for (int x = 0; x < info->cub_list.width; x++)
		{
			info->img.data[y * info->cub_list.width + x] = info->buf[y][x];
		}
	}
	if (info->save_flag == 1)
	{
		save_bmp(info);
		info->save_flag = 0;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int win_close()
{
	exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->cub_list.n_texture, &img);
	load_image(info, info->texture[1], info->cub_list.s_texture, &img);
	load_image(info, info->texture[2], info->cub_list.w_texture, &img);
	load_image(info, info->texture[3], info->cub_list.e_texture, &img);
	if (info->cub_list.sprite_flag == 1)
		load_image(info, info->texture[4], info->cub_list.sprite, &img);
}

void	init_info(t_info *info, int fd)
{
	int buffer_size;
	int i;
	char **line;
	// int fd;

	buffer_size = 10;
    // fd = open(argv[1], O_RDONLY);
	info->cub_list.map_x = 0;
	info->cub_list.map_y = 0;
	info->cub_list.size = 0;
	info->cub_list.sprite_flag = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, buffer_size);
		cub_line_check(line, &info);
		free(line);
	}
	convert_int_matrix(&info);
	if (info->cub_list.sprite_flag == 1)
		get_sprite_pos(&info);
	info->mlx = mlx_init();
}

int	main(int argc, char *argv[])
{
	t_info info;
	// int buffer_size;
	int fd;
	int i;
	int sizex;
	int sizey;
	// char **line;
	char *sin;
	
	if (argc != 2 && argc != 3)
	{
		printf("Error\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	init_info(&info, fd);
	printf("ok\n");
	// buffer_size = 10;
    // fd = open(argv[1], O_RDONLY);
	// info.cub_list.map_x = 0;
	// info.cub_list.map_y = 0;
	// info.cub_list.size = 0;
	// info.cub_list.sprite_flag = 0;
	// i = 1;
	// while (i > 0)
	// {
	// 	i = get_next_line(fd, &line, buffer_size);
	// 	cub_line_check(line, &info);
	// 	free(line);
	// }
	// convert_int_matrix(&info);
	// if (info.cub_list.sprite_flag == 1)
	// 	get_sprite_pos(&info);
	// info.mlx = mlx_init();
	mlx_get_screen_size(info.mlx, &sizex, &sizey);
	info.cub_list.width = sizex;
	info.cub_list.height = sizey;
	info.save_flag = 0;
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			info.save_flag = 1;
	}
	if (!(info.buf = (int **)malloc(sizeof(int *) * (info.cub_list.height))))
		return (-1);
	i = 0;
	while (i < info.cub_list.height)
	{
		if (!(info.buf[i] = (int *)malloc(sizeof(int) * (info.cub_list.width))))
			return (-1);
		i++;
	}
	for (int i = 0; i < info.cub_list.height; i++)
	{
		for (int j = 0; j < info.cub_list.width; j++)
		{
			info.buf[i][j] = 0;
		}
	}
	if (!(info.texture = (int **)malloc(sizeof(int *) * 11)))
		return (-1);
	for (int i = 0; i < 11; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info.texture[i][j] = 0;
		}
	}
	load_texture(&info);
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	info.win = mlx_new_window(info.mlx, info.cub_list.width, info.cub_list.height, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.cub_list.width, info.cub_list.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 33, 1<<33, &win_close, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);
	mlx_loop(info.mlx);
}
