/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:28:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/29 21:17:26 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw(t_info *info)
{
	int x;
	int y;

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

int win_close()
{
	exit(0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	if (teture[0] == NULL)
		printf("no\n");
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
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

int	main(int argc, char *argv[])
{
	t_info info;
	int buffer_size;
	int fd;
	int i;
	int j;
	int sizex;
	int sizey;
	int count;
	char **line;
	char *sin;
	
	if (argc != 2)
	{
		printf("Error\n");
		printf("The number of arguments is wrong\n");
		exit(1);
	}
	buffer_size = 10;
	i = ft_strlen(argv[1]);
	if ((i = ft_strlen(argv[1])) < 5)
	{
		printf("Error\n");
		printf("Map file is wrong\n");
		exit(1);
	}
	if (strcmp(&argv[1][i - 4], ".cub") != 0)
	{
		printf("Error\n");
		printf("Not a cub file\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		printf("%s\n", strerror(errno));
		exit(1);
	}
	info.cub_list.map_x = 0;
	info.cub_list.map_y = 0;
	info.cub_list.size = 0;
	info.cub_list.sprite_flag = 0;
	info.cub_list.init_pos_count = 0;
	info.cub_list.line_num = 0;
	count = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, buffer_size);
		count++;
		cub_line_check(line, count, &info);
		free(line);
	}
	convert_int_matrix(&info);
	if (info.cub_list.sprite_flag == 1)
		get_sprite_pos(&info);
	info.mlx = mlx_init();
	mlx_get_screen_size(info.mlx, &sizex, &sizey);
	info.cub_list.width = sizex;
	info.cub_list.height = sizey;
	if (!(info.buf = (int **)malloc(sizeof(int *) * (info.cub_list.height))))
	{
		printf("Error\n");
		printf("Malloc failed\n");
		exit(1);
	}
	i = 0;
	while (i < info.cub_list.height)
	{
		if (!(info.buf[i] = (int *)malloc(sizeof(int) * (info.cub_list.width))))
		{
			printf("Error\n");
			printf("Malloc failed\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < info.cub_list.height)
	{
		j = 0;
		while (j < info.cub_list.width)
		{
			info.buf[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!(info.texture = (int **)malloc(sizeof(int *) * 5)))
	{
		printf("Error\n");
		printf("Malloc failed\n");
		exit(1);
	}
	i = 0;
	while (i < 5)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
		{
			printf("Error\n");
			printf("Malloc failed\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			info.texture[i][j] = 0;
			j++;
		}
		i++;
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
