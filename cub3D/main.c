/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:28:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/31 21:51:56 by hkubo            ###   ########.fr       */
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

int		main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

void get_xpm_size(t_info *info, char *line)
{
	char **xpm;
	int i;
	
	if (!(xpm = ft_split(&line[1], ' ')))
		error_process("ft_split failed");
	i = 0;
	if (ft_atoi(xpm[0]) == 64 && ft_atoi(xpm[1]) == 64)
		printf("ok\n");
	else
		error_process("xpm file is wrong");
	printf("line: %s\n", line);
}

void xpm_file_check(t_info *info, int i, char *path)
{
	int		buffer_size;
	int		fd;
	int		count;
	char	**line;

	buffer_size = 10;
	printf("path: %s\n", path);
	fd = open(path, O_RDONLY);
	printf("fd: %d\n", fd);
	if (fd == -1)
		error_process(strerror(errno));
	info_init(info);
	count = 0;
	while (i > 0 && count < 4)
	{
		i = get_next_line(fd, &line, buffer_size);
		if (count == 3)
			get_xpm_size(info, line);
		count++;
		free(line);
	}
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	xpm_file_check(info, 1, path);
	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width,
		&img->img_height)))
		error_process("The path of texture is wrong");
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
		&img->endian);
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
	{
		// xpm_file_check(info, 1, info->cub_list.sprite);
		load_image(info, info->texture[4], info->cub_list.sprite, &img);
	}
}

void	info_init(t_info *info)
{
	int		sizex;
	int		sizey;

	info->cub_list.map_x = 0;
	info->cub_list.map_y = 0;
	info->cub_list.size = 0;
	info->cub_list.sprite_flag = 0;
	info->cub_list.init_pos_count = 0;
	info->cub_list.line_num = 0;
	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx, &sizex, &sizey);
	info->cub_list.width = sizex;
	info->cub_list.height = sizey;
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
}

void	read_cub_line(t_info *info, int i, char *path)
{
	int		buffer_size;
	int		fd;
	int		count;
	char	**line;

	buffer_size = 10;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_process(strerror(errno));
	info_init(info);
	count = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, buffer_size);
		count++;
		cub_line_check(line, count, info);
		free(line);
	}
}

void	buf_init(t_info *info, int i, int j)
{
	while (i < info->cub_list.height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) *
			(info->cub_list.width))))
			error_process("Malloc failed");
		i++;
	}
	i = 0;
	while (i < info->cub_list.height)
	{
		j = 0;
		while (j < info->cub_list.width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	texture_init(t_info *info, int i, int j)
{
	while (i < 5)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) *
			(texHeight * texWidth))))
			error_process("Malloc failed");
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	t_info	info;
	int		i;
	int		j;

	if (argc != 2)
		error_process("The number of arguments is wrong");
	i = ft_strlen(argv[1]);
	if ((i = ft_strlen(argv[1])) < 5)
		error_process("Map file is wrong");
	if (strcmp(&argv[1][i - 4], ".cub") != 0)
		error_process("Not a cub file");
	read_cub_line(&info, i, argv[1]);
	convert_int_matrix(&info);
	if (info.cub_list.sprite_flag == 1)
		get_sprite_pos(&info);
	if (!(info.buf = (int **)malloc(sizeof(int *) * (info.cub_list.height))))
		error_process("Malloc failed");
	buf_init(&info, 0, 0);
	if (!(info.texture = (int **)malloc(sizeof(int *) * 5)))
		error_process("Malloc failed");
	texture_init(&info, 0, 0);
	load_texture(&info);
	info.win = mlx_new_window(info.mlx, info.cub_list.width,
		info.cub_list.height, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.cub_list.width,
		info.cub_list.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
		&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 33, 1 << 33, &win_close, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &info);
	mlx_loop(info.mlx);
}
