/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:28:08 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/26 17:45:05 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// char			*ft_itoa_hex(unsigned int n, char *arg)
// {
// 	int				len;
// 	unsigned int	i;
// 	unsigned int	j;
// 	char			*ans;

// 	i = n / 16;
// 	if (i != 0)
// 	{
// 		len = 2;
// 		while (i > 16)
// 		{
// 			len++;
// 			i = i / 16;
// 		}
// 	}
// 	else
// 		len = 1;
// 	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
// 		return (NULL);
// 	ans[len] = '\0';
// 	i = n;
// 	len--;
// 	if (i == 0)
// 	{
// 		ans[0] = '0';
// 		return (ans);
// 	}
// 	while (i > 0)
// 	{
// 		j = i % 16;
// 		ans[len] = arg[j];
// 		i = i / 16;
// 		len--;
// 	}
// 	return (ans);
// }

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

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int map_line_check(char **line_split)
{
	int i;
	int j;
	
	i = 0;
	while (line_split[i])
	{
		j = 0;
		while (line_split[i][j])
		{
			if (line_split[i][j] != '0' && line_split[i][j] != '1' && line_split[i][j] != '2' 
			&& line_split[i][j] != 'N' && line_split[i][j] != 'S' && line_split[i][j] != 'E' && line_split[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_strchr_place(const char *str, int c)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(str))
	{
		if (str[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

int hex_to_decimal(char *hex)
{
	int i;
	int j;
	int ans;
	int hex_pow;
	
	ans = 0;
	printf("hex: %s\n", hex);
	i = 0;
	while (i < ft_strlen(hex))
	{
		hex_pow = 1;
		j = 0;
		while (j < i)
		{
			hex_pow *= 16;
			j++;
		}
		printf("hex_pow: %d\n", hex_pow);
		ans += hex_pow * (ft_strchr_place("0123456789ABCDEF", hex[ft_strlen(hex) - 1 - i]));
		i++;
	}
	return (ans);
}

char *make_decimal_color(t_rgb color)
{
	char *hex;
	char *red;
	char *green;
	char *blue;
	char *tmp;
	int ans;
	
	if (!(red = ft_strdup(ft_itoa_hex(color.red, "0123456789ABCDEF"))))
		return (NULL);
	if (!(green = ft_strdup(ft_itoa_hex(color.green, "0123456789ABCDEF"))))
		return (NULL);
	if (!(blue = ft_strdup(ft_itoa_hex(color.blue, "0123456789ABCDEF"))))
		return (NULL);
	if (!(hex = ft_strjoin(red, green)))
		return (NULL);
	if (!(tmp = ft_strdup(hex)))
		return (NULL);
	free(hex);
	if (!(hex = ft_strjoin(tmp, blue)))
		return (NULL);
	free(red);
	free(green);
	free(blue);
	free(tmp);
	ans = hex_to_decimal(hex);
	return (ans);
}

int line_check(char **line, t_info *info)
{
	int i;
	char *map_line;
	char **line_split;
	char **rgb_split;
	char **tmp;
	
	if (!(line_split = ft_split(line, ' ')))
		return (-1);
	if (line_split[0] == NULL)
		return (0);
	else if (i = ft_strcmp("NO", line_split[0]) == 0)
		info->cub_list.n_texture = line_split[1];
	else if (i = ft_strcmp("SO", line_split[0]) == 0)
		info->cub_list.s_texture = line_split[1];
	else if (i = ft_strcmp("WE", line_split[0]) == 0)
		info->cub_list.w_texture = line_split[1];
	else if (i = ft_strcmp("EA", line_split[0]) == 0)
		info->cub_list.e_texture = line_split[1];
	else if (i = ft_strcmp("S", line_split[0]) == 0)
	{
		info->cub_list.sprite = line_split[1];
		info->cub_list.sprite_flag = 1;
	}
	else if (i = ft_strcmp("F", line_split[0]) == 0)
	{
		if (!(rgb_split = ft_split(line_split[1], ',')))
			return (-1);
		info->cub_list.floor.red = ft_atoi(rgb_split[0]);
		info->cub_list.floor.green = ft_atoi(rgb_split[1]);
		info->cub_list.floor.blue = ft_atoi(rgb_split[2]);
		info->cub_list.floor_dec = make_decimal_color(info->cub_list.floor);
	}
	else if (i = ft_strcmp("C", line_split[0]) == 0)
	{
		if (!(rgb_split = ft_split(line_split[1], ',')))
			return (-1);
		info->cub_list.ceiling.red = ft_atoi(rgb_split[0]);
		info->cub_list.ceiling.green = ft_atoi(rgb_split[1]);
		info->cub_list.ceiling.blue = ft_atoi(rgb_split[2]);
		info->cub_list.ceiling_dec = make_decimal_color(info->cub_list.ceiling);
	}
	else if (map_line_check(line_split) == 0)
	{
		info->cub_list.map_y++;
		if (!(map_line = ft_strdup(line)))
			return (-1);
		if (ft_strlen(map_line) > info->cub_list.map_x)
			info->cub_list.map_x = ft_strlen(map_line);
		if (!(tmp = (char **)malloc(sizeof(char *) * (info->cub_list.map_y))))
			return (-1);
		i = 0;
		while (i < info->cub_list.map_y - 1)
		{
			if (!(tmp[i] = (char **)malloc(sizeof(char) * (ft_strlen(map_line) + 1))))
				return (-1);
			tmp[i] = info->cub_list.map[i];
			i++;
		}
		tmp[i] = map_line;
		free(info->cub_list.map);
		info->cub_list.map = tmp;
	}
	return (0);
}

int convert_int_matrix(t_info *info)
{
	int i;
	int j;
	
	if (!(info->cub_list.map_matrix = (int **)malloc(sizeof(int *) * (info->cub_list.map_y))))
		return (-1);
	i = 0;
	while (i < info->cub_list.map_y)
	{
		if (!(info->cub_list.map_matrix[i] = (int *)malloc(sizeof(int) * (info->cub_list.map_x))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		if (ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
		{
			while (j < ft_strlen(info->cub_list.map[i]))
			{
				if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
				{
					info->posX = (double)i + 0.5;
					info->posY = (double)j + 0.5;
				}
				if (info->cub_list.map[i][j] == 'N')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = -1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = 0.66;
				}
				else if (info->cub_list.map[i][j] == 'S')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = -0.66;
				}
				else if (info->cub_list.map[i][j] == 'W')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = -1.0;
					info->planeX = -0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == 'E')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = 1.0;
					info->planeX = 0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == ' ')
					info->cub_list.map_matrix[i][j] = 3;
				else
					info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
			while (j < info->cub_list.map_x)
			{
				info->cub_list.map_matrix[i][j] = 3;
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		else
		{
			while (j < info->cub_list.map_x)
			{
				if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
				{
					info->posX = (double)i + 0.5;
					info->posY = (double)j + 0.5;
				}
				if (info->cub_list.map[i][j] == 'N')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = -1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = 0.66;
				}
				else if (info->cub_list.map[i][j] == 'S')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = -0.66;
				}
				else if (info->cub_list.map[i][j] == 'W')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = -1.0;
					info->planeX = -0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == 'E')
				{	
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = 1.0;
					info->planeX = 0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == ' ')
					info->cub_list.map_matrix[i][j] = 3;
				else
					info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		write(1, "\n", 1);
		i++;
	}

	return (0);
}

int	main(int argc, char *argv[])
{
	t_info info;
	int buffer_size;
	int fd;
	int i;
	int sizex;
	int sizey;
	char **line;
	char *sin;
	
	if (argc != 2 && argc != 3)
	{
		printf("Error\n");
		return (-1);
	}
	buffer_size = 10;
    fd = open(argv[1], O_RDONLY);
	info.cub_list.map_x = 0;
	info.cub_list.map_y = 0;
	info.cub_list.size = 0;
	info.cub_list.sprite_flag = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, buffer_size);
		line_check(line, &info);
		// printf("~~~fd: %d line: %s first: %c return: %d~~~\n", fd, line, line[0], i);
		free(line);
	}
	printf("map_x: %d\n", info.cub_list.map_x);
	i = 0;
	while (i < info.cub_list.map_y)
	{
		printf("line: %s\n", info.cub_list.map[i]);
		i++;
	}
	convert_int_matrix(&info);
	printf("initX: %d initY: %d\n", (int)info.posX, (int)info.posY);
	if (info.cub_list.sprite_flag == 1)
		get_sprite_pos(&info);
	info.mlx = mlx_init();
	mlx_get_screen_size(info.mlx, &sizex, &sizey);
	info.cub_list.width = sizex;
	info.cub_list.height = sizey;
	printf("sizex: %d sizey: %d\n", info.cub_list.width, info.cub_list.height);
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
