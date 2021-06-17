/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:54:14 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/17 11:26:56 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_xpm_size(t_info *info, char *line)
{
	char	**xpm;

	xpm = ft_split(&line[1], ' ');
	if (xpm == NULL)
		error_process(info, "ft_split failed");
	if (ft_atoi(xpm[0]) != 64 || ft_atoi(xpm[1]) != 64)
	{
		double_array_free(xpm);
		error_process(info, "xpm file size is wrong");
	}
	double_array_free(xpm);
}

void	xpm_file_check(t_info *info, int i, char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_process(info, strerror(errno));
	count = 0;
	while (i > 0)
	{
		i = get_next_line(fd, &line, 0);
		if (i == -1)
			error_process(info, "get_next_line failed");
		if (count == 3)
			get_xpm_size(info, line);
		count++;
		free(line);
	}
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	xpm_file_check(info, 1, path);
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width,
			&img->img_height);
	if (img->img == NULL)
		error_process(info, "The path of texture is wrong");
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

	load_image(info, info->texture[0], info->cub_list.s_texture, &img);
	load_image(info, info->texture[1], info->cub_list.n_texture, &img);
	load_image(info, info->texture[2], info->cub_list.e_texture, &img);
	load_image(info, info->texture[3], info->cub_list.w_texture, &img);
}
