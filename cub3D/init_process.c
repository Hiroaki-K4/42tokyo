/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:47:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/03 21:33:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	info_init(t_info *info)
{
	int	sizex;
	int	sizey;

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
	while (i < 5)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (info->texture[i] == NULL)
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
