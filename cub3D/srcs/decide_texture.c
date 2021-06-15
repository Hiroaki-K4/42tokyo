/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:09:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/13 11:31:53 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	face_north(t_info *info)
{
	if (info->side == 1)
	{
		if (info->raydir_y > 0)
			info->tex_num = 3;
		else
			info->tex_num = 2;
	}
	else
		info->tex_num = 0;
}

void	face_south(t_info *info)
{
	if (info->side == 1)
	{
		if (info->raydir_y > 0)
			info->tex_num = 3;
		else
			info->tex_num = 2;
	}
	else
		info->tex_num = 1;
}

void	face_west(t_info *info)
{
	if (info->side == 0)
	{
		if (info->raydir_x > 0)
			info->tex_num = 1;
		else
			info->tex_num = 0;
	}
	else
		info->tex_num = 2;
}

void	face_east(t_info *info)
{
	if (info->side == 0)
	{
		if (info->raydir_x > 0)
			info->tex_num = 1;
		else
			info->tex_num = 0;
	}
	else
		info->tex_num = 3;
}

void	decide_texture(t_info *info)
{
	info->tex_num = info->cub_list.map_matrix[info->mapX][info->mapY];
	if (info->tex_num == 1)
	{
		if (fabs(info->dir_x) >= fabs(info->dir_y) && info->dir_x <= 0)
			face_north(info);
		else if (fabs(info->dir_x) >= fabs(info->dir_y) && info->dir_x >= 0)
			face_south(info);
		else if (fabs(info->dir_y) >= fabs(info->dir_x) && 0 >= info->dir_y)
			face_west(info);
		else if (fabs(info->dir_y) >= fabs(info->dir_x) && info->dir_y >= 0)
			face_east(info);
	}
}
