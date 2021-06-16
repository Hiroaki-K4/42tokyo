/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:47:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/16 22:15:48 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	info_init(t_info *info)
{
	int	sizex;
	int	sizey;

	info->cub_list.n_count = 0;
	info->cub_list.s_count = 0;
	info->cub_list.e_count = 0;
	info->cub_list.w_count = 0;
	info->cub_list.f_count = 0;
	info->cub_list.c_count = 0;
	info->cub_list.map_x = 0;
	info->cub_list.map_y = 0;
	info->cub_list.size = 0;
	info->cub_list.init_pos_count = 0;
	info->cub_list.line_num = 0;
	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx, &sizex, &sizey);
	info->cub_list.width = sizex;
	info->cub_list.height = sizey;
	info->movespeed = 0.05;
	info->rotspeed = 0.05;
}

void	buf_init(t_info *info, int i, int j)
{
	while (i < info->cub_list.height)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * (info->cub_list.width));
		if (info->buf[i] == NULL)
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
	while (i < 4)
	{
		info->texture[i] = (int *)malloc(sizeof(int)
				* (TEX_HEIGHT * TEX_WIDTH));
		if (info->texture[i] == NULL)
			error_process("Malloc failed");
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	arg_error_check(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		error_process("The number of arguments is wrong");
	i = ft_strlen(argv[1]);
	if (i < 5)
		error_process("Map file is wrong");
	if (strcmp(&argv[1][i - 4], ".cub") != 0)
		error_process("Not a cub file");
}

void	insert_null(t_info *info)
{
	info->buf = NULL;
	info->texture = NULL;
	info->cub_list.map_matrix = NULL;
	info->cub_list.map = NULL;
	info->cub_list.n_texture = NULL;
	info->cub_list.s_texture = NULL;
	info->cub_list.e_texture = NULL;
	info->cub_list.w_texture = NULL;
	info->win = NULL;
	info->img.img = NULL;
	info->mlx = NULL;
}
